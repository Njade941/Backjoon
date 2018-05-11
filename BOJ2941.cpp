#include <iostream>
#include <string>
using namespace std;

int findnum (string& str) {
    int len = str.length();
    char prevChar = str[0];
    for (int i = 1; i < str.length(); i++) {
        if ((str[i] == '-' && (prevChar == 'c' || prevChar == 'd')) ||
            (str[i] == '=' && (prevChar == 'c' || prevChar == 'z' || prevChar == 's')) ||
            (str[i] == 'j' && (prevChar == 'l' || prevChar == 'n'))) {
            len--;
        } 
        if (i > 1 && str[i] == '=' && prevChar == 'z' && str[i - 2] == 'd')
            len--;
        prevChar = str[i];
    }
    return len;
}

int main() {
    string str;
    cin >> str;

    int result = findnum(str);

    cout << result << endl;
}