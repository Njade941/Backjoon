#include <iostream>
using namespace std;

int main() {
    int result = 0;
    for (int i = 0; i < 5; ++i) {
        int n;
        cin >> n;
        if (n < 40)
            n = 40;
        result += n;
    }
    cout << result / 5 << endl;
}