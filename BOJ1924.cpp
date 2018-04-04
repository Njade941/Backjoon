#include <iostream>
using namespace std;

int main () {
    int date[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ;
    enum { SUN, MON, TUE, WED, THU, FRI, SAT } ;
    
    int x, y ;
    cin >> x >> y ;
    
    int n = 0 ;
    for ( int i = 0 ; i < x - 1 ; ++ i) {
        n += date[i] ;
    }
    
    n += y ;
   switch( n % 7 ) {
       case SUN:
           cout << "SUN" << endl ; 
           break ;
       case MON:
           cout << "MON" << endl ; 
           break ;
       case TUE:
           cout << "TUE" << endl ; 
           break ;
       case WED:
           cout << "WED" << endl ; 
           break ;
       case THU:
           cout << "THU" << endl ; 
           break ;
       case FRI:
           cout << "FRI" << endl ; 
           break ;
       case SAT:
           cout << "SAT" << endl ; 
           break ;  
           
   }
        
}