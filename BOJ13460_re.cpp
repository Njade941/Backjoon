#include <iostream>
using namespace std;

const int INF = 123456789;
int N, M;
char map[10][10];
pair<int, int>  blue, red;
int dxs[4] = { 1, -1, 0, 0 };
int dys[4] = { 0, 0, 1, -1 };

int Move(pair<int, int>& ball, int dx, int dy) {
    int& x = ball.first;
    int& y = ball.second;

    int md = 0;
    while (map[y][x] != '#' && map[y][x] != 'O') {
        y += dy;
        x += dx;
        md++;
    }
    if (map[y][x] == '#') {
        x -= dx;
        y -= dy;
    }
    else {
        x = INF;
        y = INF;
    }
    return md;
}

void Check(int mr, int mb, int dx, int dy) {
    if (red == blue && red.first != INF) {
        if (mr > mb) {
            red.first -= dx;
            red.second -= dy;
        }
        else {
            blue.first -= dx;
            blue.second -= dy;
        }
    }
}

int Solve(int cnt) {
    if (cnt > 10 || blue.first == INF) return INF;

    if (red.first == INF) return cnt;

    int ret = INF;
    pair<int, int> origin_red = red;
    pair<int, int> origin_blue = blue;

    for (int i = 0; i < 4; i++) {
        int mr = Move(red, dxs[i], dys[i]);
        int mb = Move(blue, dxs[i], dys[i]);
        Check(mr, mb, dxs[i], dys[i]);
        
        ret = min(ret, Solve(cnt+1));

        red = origin_red;
        blue = origin_blue;  
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> map[y][x];
            if (map[y][x] == 'B') {
                blue.first = x;
                blue.second = y;
            }
            if (map[y][x] == 'R') {
                red.first = x;
                red.second = y;
            }
        }
    }
    
    int result = Solve(0);
    if (result == INF) {
        result = -1;
    }
    cout << result << endl;
    return 0;
}
