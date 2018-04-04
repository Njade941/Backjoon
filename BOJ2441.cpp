#include <iostream>
using namespace std;

int main () {
    int n ;
    cin >> n ;
    
    for ( int y = n - 1 ; y >= 0 ; -- y) {
        for ( int x = - ( n - 1 ) ; x <= 0; ++ x ) {
            if ( y >= -x ) {
                cout << "*" ;
            } else {
                cout << " " ;
            }
        }
        cout << endl;
    }
}