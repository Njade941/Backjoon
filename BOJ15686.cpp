#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 123456789;
int N, M;
int home_x[100];
int home_y[100];
int store_x[13];
int store_y[13];
int dist[100][13];
int num_home = 0;
int num_store = 0;

int Chicken(vector<int>& stores) {
    int ret = 0;
    for (int i = 0; i < num_home; i++) {
        int temp_dist = INF;
        for (int j = 0; j < stores.size(); j++) {
            int store = stores[j];
            temp_dist = min(temp_dist, dist[i][store]);
        }
        ret += temp_dist;
    }
    return ret;
}

int Solve(int order, vector<int>& stores) {
    if (stores.size() == M) return Chicken(stores);

    int ret = INF;
    for (int i = order; i < num_store; i++) {
        stores.push_back(i);
        ret = min(ret, Solve(i+1, stores));
        stores.pop_back();
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int temp;
            cin >> temp;
            if (temp == 1) {
                home_x[num_home] = x;
                home_y[num_home] = y;
                num_home++;
            }
            if (temp == 2) {
                store_x[num_store] = x;
                store_y[num_store] = y;
                num_store++;
            }
        }
    }

    for (int i = 0; i < num_home; i++) {
        for (int j = 0; j < num_store; j++) {
            dist[i][j] = abs(store_x[j] - home_x[i]) + abs(store_y[j] - home_y[i]);
        }
    }

    vector<int> stores;
    cout << Solve(0, stores) << endl;
    return 0;
}
