#include <iostream>
#include <queue>
using namespace std;

int N, K, L;
int map[100][100] = { 0, };

queue<pair<int, int> > snake;

int snake_dir = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int seconds[101] = { 0, };
int directions[101] = { 0, };

int timer = 0;
int change = 0;

bool Check(int x, int y) {
    bool inside = x >= 0 && x < N && y >= 0 && y < N;
    bool crush = map[y][x] != 2;
    return inside && crush;
}

void Go(int x, int y) {
    if (map[y][x] == 0) {
        map[snake.front().second][snake.front().first] = 0;
        snake.pop();
    }
    snake.push(make_pair(x, y));
    map[y][x] = 2;    
}

void Change_dir() {
    timer++;
    if (seconds[change] == timer) {
        snake_dir = (snake_dir + directions[change]) % 4;
        snake_dir = snake_dir == -1 ? 3 : snake_dir;
        change++;
    }
}

int Solve() {
    map[0][0] = 2;

   snake.push(make_pair(0, 0));
    
    int next_x = 0 + dx[snake_dir];
    int next_y = 0 + dy[snake_dir];
    
    while (Check(next_x, next_y)) {
        Go(next_x, next_y);        
        Change_dir();
        next_x = snake.back().first + dx[snake_dir];
        next_y = snake.back().second + dy[snake_dir];
    }
    return timer+1;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < K; i++) { 
        int x, y;
        cin >> y >> x;
        map[y-1][x-1] = 1;
    }

    cin >> L;
    
    for (int i = 0; i < L; i++) { 
        int X;
        char C;
        cin >> X >> C;
        seconds[i] = X;
        directions[i] = C == 'D' ? 1 : -1;
    }

    cout << Solve() << endl;
    return 0;
}
