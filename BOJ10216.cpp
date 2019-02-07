#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int xs[3000];
int ys[3000];
int rs[3000];
vector<int> adj[3000];
bool visited[3000];

int L2(int n1, int n2) {
    return (n1-n2) * (n1-n2);
}

bool IsGroup(int i, int j) {
    return L2(xs[i], xs[j]) + L2(ys[i], ys[j]) <= (rs[i] + rs[j]) * (rs[i] + rs[j]);
}

void MakeGraph() {
    for (int i = 0; i < N; i++) { 
        adj[i].clear();
    }

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (IsGroup(i , j)) {
                adj[i].push_back(j);
                adj[j].push_back(i);                
            }
        }
    }
}

void Dfs(int here) {
    visited[here] = true;

    for (int i = 0; i < adj[here].size(); i++) {
        if (!visited[adj[here][i]]) {
            Dfs(adj[here][i]);
        }
    }
}

int Solve() {
    memset(visited, false, sizeof(visited));

    int ret = 0;
    for (int i = 0;  i < N; i++) {
        if (!visited[i]) {
            Dfs(i);
            ret++;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        cin >> N;
        
        for (int i = 0; i < N; i++) {
            cin >> xs[i] >> ys[i] >> rs[i];
        }

        MakeGraph();    
        cout << Solve() << endl;
    } 
}