#include <iostream>
using namespace std;

int CalNum ( const int &);
int main () {
    int N;
    
    cin >> N ;

    cout << CalNum(N);
}

int CalNum ( const int& N ) {
    
    if ( N % 5 == 0 ) 
        return N / 5 ;
    
    int i = N / 5 ;
    int j ; 
    while ( i >= 0 ) {
        if ( (N - 5 * i) % 3 == 0 ) {
            j = (N - 5 * i) / 3 ;
            break;
        }
        --i ;
    }

    if ( 5 * i + 3 * j == N )
        return i + j;
    
    return -1 ;
}