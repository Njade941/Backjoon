#include <iostream>
using namespace std;

int findYear (int M, int N, int x, int y) {
    for (int i = 0; i <= N; i++) {
        int year = M * i + x;
        if (year % N == y || (N == y && year % N == 0)) {
            return year;
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        
        int result = findYear(M , N, x , y);
        cout << result << '\n';
    }  
}