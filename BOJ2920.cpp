#include <iostream>
using namespace std;

int main() {
    int num[8];

    for (int i = 0; i < 8; ++i) {
        num[i] = i + 1;
    }

    bool dec = true;
    bool inc = true;
    for (int i = 0; i < 8; ++i) {
        int n = 0;
        cin >> n;

        if (num[i] == n && inc) {
            dec = false;
        } else if(num[7 - i] == n && dec) {
            inc = false;
        } else {
            dec = false;
            inc = false;
            break;
        }
    }
    if (inc) {
        cout << "ascending" << endl;
    } else if(dec) {
        cout << "descending" << endl;
    } else {
        cout << "mixed" << endl;
    }
}