#include <iostream>
using namespace std;

int N, M, K;

int dice_xdir = 0;
int dice_ydir = 0;

int dice[3][2] = { 0, };
int dice_d[4][2] = {
    { 2, 1 }, { 2, 0 }, { 1, 1 }, { 1, 0 }
};

int map[20][20];
int dice_x, dice_y;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool IsInside(int x, int y) {
    return x >=0 && x < M && y >= 0 && y < N;
}

void Draw(int dir) {
    int temp1 = dice[0][0];
    int temp2 = dice[0][1];
    
    int dice_dx = dice_d[dir][0];
    int dice_dy = dice_d[dir][1];

    dice[0][0] = dice[dice_dx][dice_dy];
    dice[0][1] = dice[dice_dx][(dice_dy+1)%2];
    dice[dice_dx][(dice_dy+1)%2] = temp1;
    dice[dice_dx][dice_dy] = temp2;
}

void Roll(int dir) {
    if (!IsInside(dice_x+dx[dir], dice_y+dy[dir])) return;
    dice_x += dx[dir];
    dice_y += dy[dir];

    Draw(dir);    
    if (map[dice_y][dice_x] == 0) {
        map[dice_y][dice_x] = dice[0][1];
    }    
    else {
        dice[0][1] = map[dice_y][dice_x];
        map[dice_y][dice_x] = 0;
    }
    cout << dice[0][0] << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> dice_y >> dice_x >> K;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> map[y][x];
        }
    }    

    for (int i = 0; i < K; i++) {
        int dir;
        cin >> dir;
        Roll(dir-1);
    }
 
    return 0;
}