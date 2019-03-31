#include <iostream>
#include <deque>
using namespace std;

deque<int> gear[4];
bool chk[4] = { false, };

void Rotate(int target, int dir) {
    chk[target] = true;
    int pgear = target-1;
    int ngear = target+1;

    if (pgear > -1 && !chk[pgear] && gear[target][6] != gear[pgear][2]) 
        Rotate(pgear, dir*-1);
    if (ngear < 4 && !chk[ngear] && gear[target][2] != gear[ngear][6])
        Rotate(ngear, dir*-1);

    if (dir == 1) {
        int temp = gear[target].back();
        gear[target].pop_back();
        gear[target].push_front(temp);
    }
    else {
        int temp = gear[target].front();
        gear[target].pop_front();
        gear[target].push_back(temp);
    }
    chk[target] = false;
}


int Solve() {
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int target, dir;
        cin >>  target >> dir;
        target--;
        Rotate(target, dir);
    }
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        ret += (1 << i) * gear[i][0];
    }
    return ret;
} 

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 4; i++)  {
        string temp;
        cin >> temp;    
        for (int j = 0; j < 8; j++) {
            gear[i].push_back(temp[j] - '0');
        }
    }
    
    cout << Solve() << endl;
    return 0;
}
