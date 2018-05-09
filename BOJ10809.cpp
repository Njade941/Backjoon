#include <iostream>
#include <string>
using namespace std;

int main() {
    int which[26];


    for (int i = 0; i < 26; ++i) {
        which[i] = -1;
    }

    string str;
    cin >> str;

    for(int i = 0; i < str.length(); ++i) {
        int value = static_cast<int> (str[i]) - static_cast<int> ('a');
        
        if (which[value] == -1) {
            which[value] = i;
        }
    }
    
    for (int i = 0; i < 26; ++i) {
        cout << which[i] << ' ';
    }
}