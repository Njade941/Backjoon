#include <iostream>
#include <string>
using namespace std;

int main() {
    int time[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
    string str;
    cin >> str;

    int result = 0;
    for (auto pos = str.cbegin(); pos != str.cend(); ++pos) {
        result += time[*pos - 'A'];
    } 
    cout << result << endl;
}