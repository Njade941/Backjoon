#include <iostream>
using namespace std ;

int main () {
    int c ;
    cin >> c ;

    double ratios[c] ;
    for(int i = 0 ; i < c ; ++ i ) {
        int n ;
        cin >> n ;
        int scores[n] ;

        double sum = 0 ;
        double mean ;
        for (int j = 0 ; j < n ; ++ j ) {
            cin >> scores[j] ;
            sum += scores[j] ;
        } 
        mean = sum / n ;
        int num = 0 ;
        
        for (int j = 0 ; j < n ; ++ j ) {
           if ( scores[j] > mean )
            num ++ ;
        }
       
        ratios[i] = static_cast<double> (num) / n * 100 ;
    }

    cout << fixed ;
    cout.precision(3) ;
    for( int i = 0 ; i < c ; ++ i) {
        cout << ratios[i] << '%' << endl ;
    }
}