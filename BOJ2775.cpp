#include <iostream>
using namespace std;

int numOfPeople (int k, int n) {
    int a[k + 1][n + 1] = { 0, };
    for (int i = 0; i <= n; i++) {
        a[0][i] = i;
    }

    for (int i = 0; i <= k; i++) {
        a[i][1] = 1;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 2; j <= n; j++) {
            a[i][j] = a[i][j-1] + a[i-1][j];
        }
    }
    return a[k][n];
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int k;
        int n;
        cin >> k >> n;
        cout << numOfPeople(k, n) << endl;
    }
}