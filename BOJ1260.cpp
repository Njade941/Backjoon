#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 1001;
vector<int> adj[MAX_N];
bool dfs_visited[MAX_N] = { false, };
bool bfs_visited[MAX_N] = { false, };

void DFS(int here) {
    dfs_visited[here] = true;
    cout << here << " ";
    for (int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];
        
        if (!dfs_visited[there]) {
            DFS(there);
        }
    }
}

void BFS(int start) {
    bfs_visited[start] = true;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int here = q.front();
        q.pop();
        cout << here << " ";
        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i];

            if (!bfs_visited[there]) {
                bfs_visited[there] = true;
                q.push(there);
            }
        }
    }
}

void solve(int N, int V) {
    for (int i = 0; i < N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    DFS(V);
    cout << endl;
    BFS(V);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(N, V);
    
    return 0;
}