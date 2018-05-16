#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int w;
        int h;
        int n;
        cin >> h >> w >> n;
        int myh = n % h;
        int myw;
        if ( myh == 0 ) {
            myh = h;
            myw = n / h;
        } 
        else {
            myw = n / h + 1;
        }
        cout << myh * 100 + myw << endl; 
    }
}