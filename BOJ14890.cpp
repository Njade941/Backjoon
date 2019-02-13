#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int N, L;
int map[100][100];
int temp[100];
int diff[100];

bool Check(int temp_check) {
    for (int i = 0; i < temp_check; i++) {
        if (abs(diff[i]) > 1) {
            return false;
        }
        if (diff[i] == 1 && temp[i] >= L) {
            temp[i] -= L;
        }
        else if (diff[i] == -1 && temp[i+1] >= L) {
            temp[i+1] -= L;
        }
        else {
            return false;
        }
    }
    return true;
} 

int Record(int dx, int dy, int line) {
    int temp_check = 0;
    memset(temp, 0, sizeof(temp));
    memset(diff, 0, sizeof(diff));
    
    int x = dx == 0 ? line : 0;
    int y = dy == 0 ? line : 0;
    for(int i = 0; i < N-1; i++) {
        temp[temp_check]++;
        if (map[y][x] != map[y+dy][x+dx]) {
            diff[temp_check] = map[y+dy][x+dx] - map[y][x];            
            temp_check++;
        }
        x += dx;
        y += dy;
    }
    temp[temp_check]++;
    return temp_check;
}

int Possible(int line) {
    int ret = 0;

    int temp_check = Record(1, 0, line);
    ret += Check(temp_check);

    temp_check = Record(0, 1, line);
    ret += Check(temp_check);
    
    return ret;
}

int Solve() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        int r =Possible(i);
        ret += r;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >>  N >> L;
    for (int  y = 0; y < N; y++) {
        for  (int x = 0; x < N; x++) {
            cin >> map[y][x];
        }
    }   
    cout << Solve() << endl;
    return 0;
}
