#include <iostream>
using namespace std;

int N;
int map[15][15] = { 0, };

void Cross(int row, int col, int row_dir, int col_dir, int type) {
    int next_row = row + row_dir;
    int next_col = col + col_dir;
    
    if (next_col >= 0 && next_col < N)
        map[next_row][next_col] += type;
}

void Queen(int row, int col, int type) {
    for (int i = row; i < N; i++) {
        map[i][col] += type;
    }

    for (int i = 1; i < N - row; i++) {
        Cross(row, col, i, i, type);
        Cross(row, col, i, -i, type);
    }
}

int Solve(int row, int col) {
    if (row !=0 && map[row-1][col] != 1) return 0;

    if (row == N) return 1;

    int ret = 0;
    for (int i = 0; i < N; i++) {
        Queen(row, i, 1);
        
        ret += Solve(row+1, i);
        
        Queen(row, i, -1);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cout << Solve(0, -1) << endl;

    return 0;
}
