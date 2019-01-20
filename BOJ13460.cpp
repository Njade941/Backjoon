#include <iostream>
#include <string>
using namespace std;

const int INF = 123456789;
int map[10][10];
int nrow, ncol;
pair<int, int> blue, red, target;

int ans = INF;

bool check(int wall_x, int wall_y) {
        int wall = map[wall_y][wall_x];
        if (wall != 0) {
            return true;
        }
    return false;
}

void move(pair<int, int>& ball, int moving, int direction) {
    int x = ball.first;
    int y = ball.second;
    if (x == INF) {
        return;
    }
    int ball_color = map[y][x];
    map[y][x] = 0;

    if (direction == 1) {    
        while (true) {
            x += moving;
            if (check(x, y)) {
                if (x == target.first && y == target.second) {
                    ball.first = INF;
                    ball.second = INF;
                }
                else {
                    ball.first = x - moving;
                    map[ball.second][ball.first] = ball_color;
                }
                break;
            }
        }
    }
    else {
        while (true) {
           y += moving;
            if (check(x, y)) {
                if (x == target.first && y == target.second) {
                    ball.first = INF;
                    ball.second = INF;
                }
                else {
                    ball.second = y - moving;
                    map[ball.second][ball.first] = ball_color;
                }
                break;
            }
        }
    }
}

void left() {
    if (blue.first < red.first) {
        move(blue, -1, 1);
        move(red, -1, 1);
    }
    else {
        move(red, -1, 1);
        move(blue, -1, 1);
    }       
}

void right() {
    if (blue.first > red.first) {
        move(blue, 1, 1);
        move(red, 1, 1);
    }
    else {
        move(red, 1, 1);
        move(blue, 1, 1);
    }
}

void up() {
    if (blue.second < red.second) {
        move(blue, -1, 2);
        move(red, -1, 2);
    }
    else {
        move(red, -1, 2);
        move(blue, -1, 2);
    }
}

void down() {
    if (blue.second > red.second) {
        move(blue, 1, 2);
        move(red, 1, 2);
    }
    else {
        move(red, 1, 2);
        move(blue, 1, 2);
    }
}


void reset(pair<int, int>& origin_red, pair<int, int>& origin_blue) {
    if (red.first != INF) {
        map[red.second][red.first] = 0;
    }
    if(blue.first != INF) {
        map[blue.second][blue.first] = 0;
    }
    map[origin_red.second][origin_red.first] = 1;
    map[origin_blue.second][origin_blue.first] = 1;
    red = origin_red;
    blue = origin_blue;
}

int dfs(int cnt) {
    if (cnt > 10 || blue.first == INF) return INF;
    if (red.first == INF && red.second == INF) {
        return cnt;
    }
    
    pair<int, int> origin_red = red;
    pair<int, int> origin_blue = blue;

    left();
    ans = min(ans, dfs(cnt+1));
    
    reset(origin_red, origin_blue);
    right();

    ans = min(ans, dfs(cnt+1));

    reset(origin_red, origin_blue);
    up();
    ans = min(ans, dfs(cnt+1));
    
    reset(origin_red, origin_blue);
    down();
    ans = min(ans, dfs(cnt+1));
    
    reset(origin_red, origin_blue);
    return ans;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> nrow >> ncol;
    for (int y = 0; y < nrow; y++) 
    {
        string temp;
        cin >> temp;
        for (int x = 0; x < ncol; x++) {
            if (temp[x] == '#') {
                map[y][x] = -1;
            }
            else if (temp[x] == '.') {
                map[y][x] = 0;
            }
            else if (temp[x] == 'O') {
                map[y][x] = 3;
                target = make_pair(x, y);
            }
            else if (temp[x] == 'B') {
                map[y][x] = 2;
                blue = make_pair(x, y);
            }
            else {
                map[y][x] =1;
                red = make_pair(x, y);
            }
        }
    }
    int result = dfs(0);
    if (result == INF) {
        result = -1;
    }
    cout << result << endl;
    return 0;
}