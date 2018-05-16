#include <iostream>
using namespace std;

int flyYear(long source, long destination) {
    long rest = (destination - source);
    long n = 1;
    while ( rest > n * n ) {
        n++;
    }

    rest -= (n - 1) * (n - 1);
    
    if (rest == 0) {
        rest = 0;
    }
    else if (rest < n) {
        rest = 1;
    }
    else {  
        rest  = 2;
    }
    return 2 * (n-1) - 1 + rest;
}

int main() {
    int numOfCase;
    cin >> numOfCase;
    for (int i = 0; i < numOfCase; ++i) {
        long source, destination;
        cin >> source >> destination;
        cout << flyYear(source, destination) << '\n';
    }
}