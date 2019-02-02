#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int adj[501][501];
int visit[501];

int n, m;
int Bfs() {
    visit[1] = 0;

    queue<int> q;
    q.push(1);
    
    int ret = 0;

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (adj[here][i] && visit[i] == -1) {
    
                visit[i] = visit[here] + 1;
                
                if (visit[i] < 3) {
                    q.push(i);
                    ret++;
                } 
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(adj, 0, sizeof(adj));
    memset(visit, -1, sizeof(visit));
    
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    cout << Bfs() << endl;
}