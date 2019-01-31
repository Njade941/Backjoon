#include <iostream>
#include <queue>
using namespace std;

int N, M ,K;
int A[10][10];
int amount[10][10];
queue<int> trees[10][10];

int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };

int add_temp[10][10];
int add[10][10];

bool IsInside(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

void Next() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int num_trees = trees[y][x].size();

            int temp = A[y][x];
            for (int i = 0; i < add[y][x]; i++) {
                if (amount[y][x] > 0) {
                    amount[y][x]--;
                    trees[y][x].push(2);
                }
            }
   
            for (int  i = 0; i < num_trees; i++) {
                int tree = trees[y][x].front();
                trees[y][x].pop();

                if (amount[y][x] >= tree) {
                    amount[y][x] -= tree;
                    ++tree;
                    trees[y][x].push(tree);

                    if (tree % 5 == 0) {
                        for (int j = 0; j < 8; j++) {
                            int next_x = x + dx[j];
                            int next_y = y + dy[j];

                            if (IsInside(next_x, next_y)) {
                                add_temp[next_y][next_x]++;
                            }
                        }
                    }
                }
                else {
                    temp += tree/2;
                }
            }
            amount[y][x] += temp;
        }
    }
}

int Solve() {
    for (int i = 0 ; i < K; i++) {
        Next();
        
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                add[y][x] = add_temp[y][x];
                add_temp[y][x] = 0;
            }
        }
    }

    int ret = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            ret += trees[y][x].size();
            ret += add[y][x];
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> A[y][x];
            amount[y][x] = 5;
        }
    }

    for (int  i = 0; i < M; i++) {
        int x, y, z;

        cin >> x >> y >> z;

        trees[x-1][y-1].push(z);
    }

    cout << Solve() << endl;
    return 0;
}
