#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_SIZE = 1000;
int map[MAX_SIZE][MAX_SIZE];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int days[MAX_SIZE][MAX_SIZE];
vector<pair<int, int> > tomato;

int N, M;

bool check() {
    for (int y = 0; y < N; y++) {
        for (int x =0; x < M; x++) {
            if (map[y][x] == 0) {
                return false;
            }
        }
    }
    return true;
}

int BFS() {
    queue<pair<int, int> > q;
    int day = 0;
    for (auto it = tomato.begin(); it < tomato.end(); ++it) {
        int x = (*it).first;
        int y = (*it).second;
        q.push(make_pair(x, y));
        days[y][x] = 0;
    }    

    while (!q.empty()) {
        int here_x = q.front().first;
        int here_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int there_x = here_x + dx[i];
            int there_y = here_y + dy[i];

            if (there_x >=0 && there_x < M && there_y >= 0 && there_y < N && 
            map[there_y][there_x] != -1 && days[there_y][there_x] == -1) {
                map[there_y][there_x] = 1;
                days[there_y][there_x] = days[here_y][here_x] + 1;
                
                q.push(make_pair(there_x, there_y));

                if (day < days[there_y][there_x]) {
                    day = days[there_y][there_x];
                }
            }
        }
    }
    return day;
}

int solve() {
    memset(days, -1, sizeof(days));
    int result = BFS();
    if (!check()) {
        return -1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    for (int y = 0; y < N; y++) {
        for (int x =0; x < M; x++) {
            int temp;
            cin >> temp;
            map[y][x] = temp;
            if (temp == 1) {
                tomato.push_back(make_pair(x, y));
            }
        }
    }
    cout << solve() << endl;

}