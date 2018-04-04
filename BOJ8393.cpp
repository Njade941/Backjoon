#include <iostream>
using namespace std;

int main () {
    int n ; 
    cin >> n ;
    
    long result = 0;
    for ( long i = 1 ; i <= n; ++ i ) {
        result += i ;
    } 
    cout << result << endl ;
}