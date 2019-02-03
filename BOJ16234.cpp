#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int A[50][50];
int unitied[50][50];
int amount[2500];
int num[2500];

int N, L, R;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool IsInside(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

bool Bfs(pair<int, int> start, int unite) {
    bool ret = false;
    queue<pair<int, int > > q;
    q.push(start);

    unitied[start.second][start.first] = unite;
    num[unite]++;
    amount[unite] += A[start.second][start.first];

    while(!q.empty()) {
        int here_x = q.front().first;
        int here_y = q.front().second;
        
        q.pop();
        for (int d = 0; d < 4; d++) {
            int there_x = here_x + dx[d];
            int there_y = here_y + dy[d];

            if (IsInside(there_x, there_y) && unitied[there_y][there_x] == -1) {
                int diff = abs(A[here_y][here_x] - A[there_y][there_x]);
                
                if (diff >= L && diff <= R) {
                    ret = true;
                    unitied[there_y][there_x] = unite;

                    q.push(make_pair(there_x, there_y));
                    num[unite]++;
                    amount[unite] += A[there_y][there_x];
                }
            }
        }
    }

    return ret;
}

bool Check() {
    memset(unitied, -1, sizeof(unitied));
    memset(num, 0, sizeof(num));
    memset(amount, 0, sizeof(amount));

    int unite = 0;
    bool ret = false;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (unitied[y][x] == -1) {
                ret = Bfs(make_pair(x, y), unite) || ret; 
                unite++;
            }
        }
    }
    return ret;
}

void Move() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int unite = unitied[y][x];
            A[y][x] = int(amount[unite] / num[unite]);
        }
    }
}

int Solve() {
    int ret = 0;
    while (Check()) {
        Move();            
        ret++;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> R;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> A[y][x];
        }
    }
    cout << Solve() << endl;
}