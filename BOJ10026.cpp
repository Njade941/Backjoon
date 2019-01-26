#include <iostream>
#include <cstring>
using namespace std;

int N;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

char map[100][100];
bool visited[100][100];
int result[2] = { 0, };
bool IsInside(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

void Dfs(int x, int y) {
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (IsInside(next_x, next_y) && !visited[next_y][next_x] && map[y][x] == map[next_y][next_x]) {
            Dfs(next_x, next_y);
        }
    }
}

int Solve() {
    for (int type = 0; type < 2; type++) {
        memset(visited, false, sizeof(visited));
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (!visited[y][x]) {
                    Dfs(x, y);
                    result[type]++;
                }

                if (map[y][x] == 'G') {
                    map[y][x] = 'R';
                }
            }
        }
    }
} 

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
        }
    }
    Solve();

    cout << result[0] << ' ' << result[1] << endl;

    return 0;
}
