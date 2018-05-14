#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int i = 1;
    while (n - i > 0) {
        n -= i;
        i++;
    }

    i++;
    int numerator;
    int denominator;
    if (i%2 == 0) {
        numerator = i - n;
        denominator = n;
    } else {
        numerator = n;
        denominator = i - n; 
    }

    cout << numerator << '/' << denominator << endl;
}