#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[100][100];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int dist[100][100];

bool IsInside(int x, int y) {
    return x >= 0 && y >= 0 && x < M && y < N;
}

int Bfs() {
    queue<pair<int, int> > q;
    
    map[0][0] = 2;
    q.push(make_pair(0, 0));
    dist[0][0] = 1;

    while (!q.empty()) {
        int here_x = q.front().first;
        int here_y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int there_x = here_x + dx[d];
            int there_y = here_y + dy[d];

            if (IsInside(there_x, there_y) && map[there_y][there_x] == 1) {
                map[there_y][there_x] = 2;
                q.push(make_pair(there_x, there_y));
                dist[there_y][there_x] = dist[here_y][here_x] + 1;
                
                if (there_x == M-1 && there_y == N-1) {
                    return dist[there_y][there_x];
                }
            }
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int y = 0; y < N; y++)    {
        string temp;
        cin >> temp;
        for (int x = 0; x < M; x++) {
            map[y][x] = temp[x] - '0';
        }
    }

    cout << Bfs() << endl;
}