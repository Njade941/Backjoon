#include <iostream>
#include <cmath>
using namespace std;

int map[20][20];
int N;
bool team[20];
const int INF = 123456789;

int Diff() {
    int team_sum1 = 0;
    int team_sum2 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (team[i] && team[j]) {
                team_sum1 += map[i][j];
            }
            else if (!team[i] && !team[j]) {
                team_sum2 += map[i][j];
            }
        }
    }
    return abs(team_sum2 - team_sum1);
}

int Solve(int start, int cnt) {
    if (cnt == N/2) return Diff();
    if (start == N) return INF;

    int ret = INF;
    for (int i = start; i < N; i++) {
        team[i] = true;
        ret = min(ret, Solve(i+1, cnt+1));
        team[i] = false;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    int ret = INF;
    ret = min(ret, Solve(0, 0));
    ret = ret == INF ? -1 : ret;
    cout << ret << endl;
}