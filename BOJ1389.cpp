#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dist[101];
vector<int> adj[101];
int N, M;

int bfs(int start) {
    dist[start] = 0;
    queue<int> q;
    q.push(start);

    int sum = 0;
    while (!q.empty()) {
        int here = q.front();
        q.pop();

        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i];

            if (dist[there] == -1) {
                dist[there] = dist[here] + 1;
                q.push(there);
                sum += dist[there];
            }
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }

    int result = 12345689;
    int minimum = 0;
    for (int i = 1; i <= N; i++) {
        memset(dist, -1, sizeof(dist));
        int temp = bfs(i);
        
        if (result > temp) {
            result = temp;
            minimum = i;
        }
    }
    
    cout << minimum << endl;
    
    return 0;
}
