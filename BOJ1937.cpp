#include <iostream>
#include <cstring>
using namespace std;

int map[500][500];
int cache[500][500];
int n;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool IsInside(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int Dfs(int x, int y) {
    int& ret = cache[y][x];

    if (ret != -1) return ret;

    ret = 1;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (IsInside(nx, ny) && map[y][x] < map[ny][nx])
            ret = max(ret, Dfs(nx, ny) + 1);
    }
    return ret;
}

int Solve() {
    memset(cache, -1, sizeof(cache));
    int ret = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            ret = max(ret, Dfs(x, y));
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }
    cout << Solve() << endl;
}