#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int count = 0;
    bool blank = true;
    for(auto pos = s.begin(); pos != s.end(); ++pos) {
        if (*pos == ' ') {
            blank = true;
        } else if (*pos != ' ' && blank) {
            count++;
            blank = false;
        }
    }
    cout << count << endl;
}