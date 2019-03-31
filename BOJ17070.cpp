#include <iostream>
using namespace std;

int N;
int map[16][16];
int dx[3] = { 1, 1, 0 };
int dy[3] = { 0, 1, 1 };

bool IsPipe(int pipe) {
    return pipe >= 0 && pipe <= 2;
}

bool IsPossible(int x, int y, int nx, int ny, int pipe) {
    if (pipe == 1) 
        return map[ny][nx] == 0 && map[ny][x] == 0 && map[y][nx] == 0;
    return map[ny][nx] == 0;
}

bool IsInside(int x, int y) {
    return x < N && y < N;
}
int Solve(int x, int y, int pipe) {
    if (x == N-1 && y == N-1) return 1;

    int ret = 0;
    for (int d = -1; d <= 1; d++) {
        int npipe = pipe + d;
        if (IsPipe(npipe)) {
            int nx = x+dx[npipe];
            int ny = y+dy[npipe];
            if (IsInside(nx, ny) && IsPossible(x, y, nx, ny, npipe)) {
                ret += Solve(nx, ny, npipe);
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int y = 0; y < N; y++) 
        for (int x = 0; x < N; x++) 
            cin >> map[y][x];


    cout << Solve(1, 0, 0) << endl;   
}