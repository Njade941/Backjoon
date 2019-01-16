#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 15;
int days[MAX_N+1];
int benefits[MAX_N+1];
vector<pair<int, int> > adj[MAX_N+1];
int N;

int dijkstra(int start) {
    priority_queue<pair<int, pair<int, int> > >pq;
    int results[N+1] = { 0, };
    int prev[N+1] = { 0, };
    for (int i = 0; i < adj[start].size(); i++) {
        pq.push(make_pair(-adj[start][i].second, make_pair(start, adj[start][i].first)));
    }

    while (!pq.empty()) {
        int benefit = -pq.top().first;
        int there = pq.top().second.second;
        int here = pq.top().second.first;

        pq.pop();
    
        results[there] = max(results[there], benefit + results[here]);

        for (int i = 0; i < adj[there].size(); i++) {
            pq.push(make_pair(-adj[there][i].second, make_pair(there, adj[there][i].first)));
        }
    } 

    int result = 0;
    for (int i = 0; i <= N; i++) {
        result = max(result, results[i]);
        
    }
    return result;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int day, benefit;
        cin >> day >> benefit;

        if (day + i - 1 > N) {
            continue;
        }
        
        benefits[i] = benefit;
        days[i] = day;

        adj[0].push_back(make_pair(i,benefit));

        for (int j = 1; j < i; j++) {
            if (j + days[j] - 1 < i) {
                adj[j].push_back(make_pair(i, benefit));
            }
        }
    }
    cout << dijkstra(0) << endl;

    return 0;
}
