#include <iostream>
using namespace std;

int main() {
    int num[10] = { 0, };

    int a, b, c;
    cin >> a >> b >> c;
    int multi = a * b * c;

    while(multi > 0) {
        int n = multi % 10;
        num[n]++;
        multi /= 10;
    }

    for (int i = 0; i < 10; ++i) {
        cout << num[i] << endl;
    }
}