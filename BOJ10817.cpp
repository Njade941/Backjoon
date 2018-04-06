#include <iostream>
using namespace std ;

int minInt ( int&, int& );

int main () {
    int a, b, c ;
    cin >> a >> b >> c ;

    int result = minInt(a, b) ^ minInt(b, c) ^ minInt(a, c) ;
    cout << result ;
}

int minInt( int& a, int& b ) {
    return a > b ? b : a ;
}
