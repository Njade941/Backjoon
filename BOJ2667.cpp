#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int cnt;
int N;

int map[25][25];
bool visited[25][25] = { false, };
vector<int> danji;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 }; 

int DFS(int x, int y) {
    visited[y][x] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int there_x = x + dx[i];
        int there_y = y + dy[i];

        if (there_x >= 0 && there_x < N && there_y >= 0 && there_y < N &&
         map[there_y][there_x] == 1 && !visited[there_y][there_x]) {
            DFS(there_x, there_y);
        }
    }
    return cnt;
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x] == 1 && !visited[y][x]) {
                cnt = 0;
                int result = DFS(x, y);
                danji.push_back(result);
            }
        }
    }
}

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
       
    cin >> N;
    for (int y = 0; y < N; y++) {
        string temp;
        cin >> temp;
        for (int x = 0; x < N; x++) {
            map[y][x] = temp[x] - '0';
        }
    }
    solve();
    sort(danji.begin(), danji.end());
    cout << danji.size() << endl;
    for (auto it = danji.begin(); it < danji.end(); ++it) {
        cout <<  *it << endl;
    }
}
