#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int num[10] = { 0, };
    do {
        int i = n % 10;
        n /= 10;
        num[i]++; 
    } while (n > 0);
    
    num[6] = (num[6] + num[9]) % 2 ? (num[6] + num[9]) / 2 + 1 : (num[6] + num[9]) / 2;
    int max = num[0];
    for (int i = 1; i < 9; i++) {
        if (max < num[i]) {
            max = num[i];
        }
    }

    cout << max << endl;
}