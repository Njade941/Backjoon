#include <iostream>
#include <string>
using namespace std;

int main() {
    int num;
    cin >> num;
    int n = 0;
    for (int i = 0; i < num; i++) {
        bool groupcheck = true;
        bool check[26] = { false, };
        string str;
        cin >> str;
        if (str.length() == 1) {
            n++;
        } else {
            for (int j = 0; j < str.length(); j++) {
                int index = static_cast<int> (str[j] - 'a');
                if (!check[index]) {
                    check[index] = true;
                } else if (str[j - 1] != str[j]) {
                    groupcheck = false;
                    break;
                }
            }
            if (groupcheck) {
                n++;
            }
        }
    }
    cout << n << endl;
}