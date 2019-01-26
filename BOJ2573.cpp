#include <iostream>
using namespace std;

int N, M;
int map[300][300];
bool visited[300][300];
int num[300][300];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool Melt() {
    for (int y = 1; y < N-1; y++) {
        for (int x = 1; x <M-1; x++) {
            num[y][x] = 0;
            visited[y][x] = false;
            if (map[y][x]) {
                for (int i = 0; i < 4; i++) {
                    num[y][x] += (map[y+dy[i]][x+dx[i]] <= 0);
                }
            }
        }   
    }
    bool end = false;
    for (int y = 1; y < N-1; y++) {
        for (int x = 1; x <M-1; x++) {
            map[y][x] -= num[y][x];
            if (map[y][x] > 0) end = true;
        }
    }
    return end;
}

void Dfs(int x, int y) {
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (map[next_y][next_x] > 0 && !visited[next_y][next_x]) {
            Dfs(next_x, next_y);
        }
    }
}

bool Check() {
    bool check = false;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (map[y][x] > 0 && !visited[y][x]) {
                if (!check) {
                    Dfs(x, y);
                    check = true;
                }
                else {
                    return true;
                }
            }
        } 
    }
    return false;
}

int Solve() {
    int result = 0;
    while (true) {
        if (Check()) return result;
        result++;
        if (!Melt()) return 0;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> map[y][x];
        }
    }
    cout << Solve() << endl;
    return 0;
}
