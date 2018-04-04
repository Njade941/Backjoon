#include <iostream>
using namespace std;

int main () {
    int n ;
    cin >> n ;
    
   for ( int y = n - 1 ; y >= 0 ; -- y ) {
       for ( int x = 0 ; x < n ; ++ x ) {
           if (x >= y) {
               cout << "*" ;
           } else {
               cout << " " ;
           }
       }
       cout << endl ;
   }
}