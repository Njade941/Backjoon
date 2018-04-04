#include <iostream>
#include <string>
using namespace std ;

int main () {
    string str ;
    cin >> str ;

    while( !str.empty() ) {
        if ( str.size() > 10 ) {
            cout << str.substr ( 0, 10 ) << endl ;
            str.erase ( str.begin(), str.begin() + 10 ) ;
        } else {
            cout << str << endl ;
            str.clear() ;
        }
    }
}