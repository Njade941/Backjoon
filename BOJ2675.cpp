#include <iostream>
#include <string>
using namespace std;

int main() {
    int num1, num2;
    cin >> num1;
    string str;
    for(int i = 0; i < num1; ++i) {
        cin >> num2 >> str;
        for (auto pos = str.cbegin(); pos != str.cend(); ++pos) {
            for (int j = 0; j < num2; ++j) {
                cout << *pos;
            }
        }
        cout << endl;
    }
}