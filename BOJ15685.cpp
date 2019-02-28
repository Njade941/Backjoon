#include <iostream>
using namespace std;

int map[101][101];
int dir[1024];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int x, y, d, g;

void Draw() {
    map[y][x] = 1;
    dir[0] = d;
    y += dy[d];
    x += dx[d];
    map[y][x] = 1;
    for (int i = 1; i <= g; i++) {
        int num = 1 << (i-1);
        int k = 0;
        for (int j = num-1; j >= 0; j--) {
            d = (dir[j] + 1) % 4;
            y += dy[d];
            x += dx[d];
            map[y][x] = 1;

            dir[num+k] = d;
            k++;
        }
    }
}

bool Square(int x, int y) {
    return (map[y][x] == 1 && map[y][x+1] == 1 && 
    map[y+1][x] == 1 && map[y+1][x+1] == 1);
}

int Solve() {
    int ret = 0;
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            if (Square(x, y)) ret++;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

   int N;
   cin >> N;
   for (int i = 0; i < N; i++) {        
        cin >> x >> y >> d >> g;
        Draw(); 
   }
   
   cout << Solve() << endl;
}