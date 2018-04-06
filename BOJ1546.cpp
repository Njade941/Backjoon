#include <iostream>
using namespace std ;

int main () {
    int n ;
    cin >> n ;

    int score[n] ;
    int max = 0 ;
    int sum = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> score[i] ;
        sum += score[i] ;
        if ( score[i] > max )
            max = score[i] ;
    } 

    double mean = static_cast<double> (sum) / static_cast<double> (max) * 100 / n ;

    cout.precision(3) ;
    cout << mean << endl ;
}