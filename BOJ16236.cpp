#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 123456789;
const int MAX_N = 20;
int map[MAX_N][MAX_N] = { 0, };
int dist[MAX_N][MAX_N];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int shark_size;
int N;
int need;

int result[3];
bool IsInside(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

void BFS(int x, int y) {
    memset(dist, -1, sizeof(dist));
   
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    dist[y][x] = 0;

    result[0] = INF;
    result[1] = INF;
    result[2] = INF;

    while (!q.empty()) {
        int here_x = q.front().first;
        int here_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int there_x = here_x + dx[i];
            int there_y = here_y + dy[i];

            if (IsInside(there_x, there_y) && (shark_size >= map[there_y][there_x]) && dist[there_y][there_x] == -1) {
                dist[there_y][there_x] = dist[here_y][here_x] + 1;
                q.push(make_pair(there_x, there_y));
                if (dist[there_y][there_x] > result[0]) {
                    return ;
                }
                if (map[there_y][there_x] > 0 && shark_size > map[there_y][there_x] &&
                 ((there_y < result[2]) || (there_y == result[2] && there_x < result[1]))) {
                    result[0] = dist[there_y][there_x];
                    result[1] = there_x;
                    result[2] = there_y;
                    
                }
            }
        }
    }
}

int solve(int x, int y) {
    shark_size = need = 2;
    int dist = 0;
    while (true) {
        BFS(x, y);
        if(result[0] == INF) {
            return dist;
        }
        dist += result[0];
        map[y][x] = 0;
        x = result[1];
        y = result[2];
        map[y][x] = 9;
        need--;
        if (need == 0) {
            shark_size++;
            need = shark_size;
        }
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int shark_x, shark_y;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int temp;
            cin >> temp;
            map[y][x] = temp;
            if (temp == 9) {
                shark_x = x;
                shark_y = y;
            }
        }
    }
    cout << solve(shark_x, shark_y) << endl;

    return 0;
}
