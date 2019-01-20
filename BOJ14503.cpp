#include <iostream>
#include <queue>
using namespace std;

int N, M;
int r, c;
int d;
int map[50][50];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int Bfs(int x, int y) {
    map[y][x] = -1;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));

    int ret = 1;
    int here_x = x;
    int here_y = y;

    while (!q.empty()) {
        here_x = q.front().first;
        here_y = q.front().second;
        
        q.pop();
        
    
        for (int i = 0; i < 4; i++) {
            int change_d = (d + i) % 4;
            int there_x = here_x + dx[change_d];
            int there_y = here_y + dy[change_d];

            if (map[there_y][there_x] == 0) {
    
                map[there_y][there_x] = -1;
                q.push(make_pair(there_x, there_y));
                ret++;

                d = (change_d + 1) % 4;
                break;
            }
        }
    }

    int there_x = here_x + dx[(d + 1) % 4];
    int there_y = here_y + dy[(d + 1) % 4];
    if (map[there_y][there_x] != 1) {
        ret += Bfs(there_x, there_y) - 1 ;
    }
    
    return ret;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    cin >> r >> c >> d;

    if (d % 2 == 1) {
        d = (d+2) % 4;
    }
    

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> map[y][x];
        }
    }
    
    cout << Bfs(c, r) << endl;
    return 0;
}
