#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[100][100];
bool visited[100][100];
int rain_h = 0;
int N;
int max_h;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool Inside(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

void Rain() {
    rain_h++;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x] < rain_h) {
                map[y][x] = -1;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
}

void Bfs(int x, int y) {
    visited[y][x] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));

    while (!q.empty()) {
        int here_x = q.front().first;
        int here_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int there_x = here_x + dx[i];
            int there_y = here_y + dy[i];

            if (Inside(there_x, there_y) && map[there_y][there_x] != -1 && !visited[there_y][there_x]) {
                q.push(make_pair(there_x, there_y));
                visited[there_y][there_x] = true;
            }
        }
    }
}

int Solve(int h) {
    int result = 0;
    for (int i = 0; i <= h; i++) {
        int num = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (map[y][x] != -1 && !visited[y][x]) {
                    Bfs(x, y);
                    num++;
                }
            }
        }
        result = max(result, num);
        Rain();
    }
    return result;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    max_h = -1;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
            max_h = max(max_h, map[y][x]);
        }
    }
    
    cout << Solve(max_h) << endl;
    return 0;
}
