#include <iostream>
using namespace std;

int N, M, H;
bool adj[31][11] = { false, };
const int INF = 987654321;
int ret = INF;

bool Connect(int n) {
    int start = n;
    for (int h = 1; h <= H; h++) {
        if (adj[h][n]) n++;
        else if (adj[h][n - 1]) n--;
    }
    if (start == n) return true;
    return false;
}

bool Possible() {
    for (int i = 1; i < N; i++) {
        if (!Connect(i)) return false;
    }
    return true;
}

void Solve(int count, int w, int h) {
    if (count >= ret) return;
    if (Possible()) {
        ret = count;
        return;
    }
    if ((h > H) || count == 3) return;

    int i = w;

    Solve(count, 1, h + 1);
    while (i < N) {

        if (adj[h][i]) {
            i += 2;
            continue;
        }

        if (adj[h][i + 1]) {
            i += 3;
            continue;
        }

        adj[h][i] = true;
        Solve(count + 1, i + 2, h);
        adj[h][i] = false;
        
        i++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> H;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = true;
    }
    
    Solve(0, 1, 1);
    
    if (ret == INF) ret = -1;
    cout << ret << endl;
}