#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

char map[12][6];

bool visited1[12][6];
bool visited2[12][6];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool IsInside(int x, int y) {
    return x >= 0 && x < 6 && y >= 0 && y <12;
}

void Stack() {
    for (int x = 0; x < 6; x++) { 
        string temp = string(12, '.');
        int temp_index = 11;
        
        for (int y = 11; y >= 0; y--) {
            if (map[y][x] != '.')
                temp[temp_index--] = map[y][x];
        }
        
        for (int y = 11; y >= 0; y--) 
            map[y][x] = temp[y];
    }
}

bool Bfs(int x, int y, char target) {
    bool ret = false;

    queue<pair<int, int> > q;
    q.push({x, y});
    
    visited1[y][x] = true;

    int cnt = 1;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (IsInside(nx, ny) && map[ny][nx] == target && !visited1[ny][nx]) {
                q.push({nx, ny});
                visited1[ny][nx] = true;
                cnt++;
            }
        }
    }
    if (cnt >= 4) {
        ret = true;
        for (int y = 0; y < 12; y++) {
            for (int x = 0; x < 6; x++) {
                if (visited1[y][x]) {
                    map[y][x] = '.';
                    visited1[y][x] = false;
                }
            }
        }
    }
    return ret;
}

int Solve() {
    bool conti = true;
    int ret = -1;
    while (conti) {
        memset(visited1, false, sizeof(visited1));

        Stack();
        ret++;
        conti = false;
        
        
        for (int y = 0; y < 12; y++) {
            for (int x = 0; x < 6; x++) {
                if (map[y][x] != '.' && !visited2[y][x]) {
                    conti = Bfs(x, y, map[y][x]) || conti;
                    for (int y = 0; y < 12; y++) {
                        for (int x = 0; x < 6; x++) {
                            visited2[y][x] = visited1[y][x];
                            visited1[y][x] = false;
                        }
                    }
                }
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int y = 0; y < 12; y++) {
        for (int x = 0; x < 6; x++) {
            cin >> map[y][x];
        }
    }
    cout << Solve() << endl;
    
}