#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
    int num[26] = { 0, };
    string str;
    cin >> str;

    transform(str.begin(), str.end(), str.begin(), ::toupper);
    for (int i = 0; i < str.length(); ++i) {
        int val = str[i] - 'A';
        num[val]++;
    }

    int currmax = 0;
    int prevmax = 0;
    if (str.length() == 1) {
        cout << str[0] << endl;
    } else {
        for (int i = 1; i < 26; ++i) {
            if (num[i] >= num[currmax]) {
                prevmax = currmax;
                currmax = i;
            }
        }
        if (currmax != prevmax && num[currmax] == num[prevmax]) {
            cout << '?' << endl;
        } else {
            cout << static_cast<char> (currmax + static_cast<int> ('A')) << endl;
        }
    }
    
}