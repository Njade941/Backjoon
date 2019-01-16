#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 20;
int ncol, nrow;
int map[MAX_N][MAX_N];

const int ALPHA_N = 26;
bool check[ALPHA_N] = { false, };

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool IsInside(int x, int y) {
    return (x >= 0 && x < ncol && y >= 0 && y < nrow);
}

int solve(int x, int y, int count) {
    check[map[y][x]] = true;
    int result = count;
    for (int i = 0; i < 4; i++) {
        int there_x = x + dx[i];
        int there_y = y + dy[i];
        if (IsInside(there_x, there_y) && !check[map[there_y][there_x]]) {
            result = max(result, solve(there_x, there_y, count+1));

            check[map[there_y][there_x]] = false;
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> nrow >> ncol; 
    for (int y = 0; y < nrow; y++) {
        string temp;
        cin >> temp;
        for (int x = 0; x < ncol; x++) {
            map[y][x] = temp[x] - 'A';
        }
    }
    
    cout << solve(0, 0, 1) << endl;

    return 0;
}
