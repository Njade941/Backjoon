#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

class point {
public:
    int x, y, z;
    point(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

const int MAX_N = 100;
int M, N , H;
int map[MAX_N][MAX_N][MAX_N];
int days[MAX_N][MAX_N][MAX_N];

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
vector<point> tomato;

bool isinside(int x , int y, int z) {
    return (x >= 0 && y >= 0 && z >= 0 && x < M && y < N && z < H);
}

bool check() {
    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (map[z][y][x] == 0)
                    return false;
            }
        }
    }
    return true;
}

int bfs() {
    queue<point> q;
    for (auto it = tomato.begin(); it < tomato.end(); ++it) {
        point  p = *it;
        q.push(p);
        days[p.z][p.y][p.x] = 0;
    }
    
    int day = 0;

    while (!q.empty()) {
        int z = q.front().z;
        int y = q.front().y;
        int x = q.front().x;
        
        q.pop();
        
        for (int i = 0; i < 6; i++) {
            int there_z = z + dz[i];
            int there_y = y + dy[i];
            int there_x = x + dx[i];
            
            if (isinside(there_x, there_y, there_z) &&
             map[there_z][there_y][there_x] != -1 && days[there_z][there_y][there_x] == -1) { 
                 map[there_z][there_y][there_x] = 1;
                 days[there_z][there_y][there_x] = days[z][y][x] + 1;

                q.push(point(there_x, there_y, there_z));

                 if (days[there_z][there_y][there_x] > day) {
                     day = days[there_z][there_y][there_x];
                 }
            }
        }
    }
    return day;
}

int solve() {
    int result = bfs();
    if (!check()) {
        return -1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(days, -1, sizeof(days));
    memset(map, -1, sizeof(map));
    cin >> M >> N >> H;
    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                int temp;
                cin >> temp;
                map[z][y][x] = temp;
                if (temp == 1) {
                    tomato.push_back(point(x, y, z));
                }
            }
        }    
    }
    cout << solve() << endl;;
}