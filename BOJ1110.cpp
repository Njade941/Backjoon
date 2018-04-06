#include <iostream>
using namespace std ;

int main () {
    int a ;
    cin >> a ;

    int b = a ;
    int r = 0 ;
    do {
        int c = b % 10 ;
        int d = b / 10 ;

        b = (c * 10) + ((c + d) % 10) ; 
        r ++ ;
    }   while ( b != a ) ;
    cout << r << endl ;
}