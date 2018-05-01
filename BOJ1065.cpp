#include <iostream>
using namespace std;

bool isHansu(int num) {
    int prev = num % 10;
    num = num / 10;
    int curr = num % 10;
    int d = curr - prev;
    num = num / 10;

    while (num > 0) {
        prev = curr;
        curr = num % 10;
        if(d != curr - prev)
            return false;
        num = num / 10;
    }
    return true;
}

int main() {
    int num;
    cin >> num;
    int numOfHansu = 0;
    for (int i = 1; i <= num; ++i) {
        if (isHansu(i))
            numOfHansu++;
    }
    cout << numOfHansu << endl;
}

