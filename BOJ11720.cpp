#include <iostream>
using namespace std;

int main () {
    int n ;
    cin >> n ;

    int result = 0 ;

    for( int i = 0 ; i < n ; ++ i ) {
        char c ;
        cin >> c ;
        result += static_cast <int> ( c - '0' ) ;
    }    
    cout << result << endl;
}