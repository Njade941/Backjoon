#include <iostream>
using namespace std;

int findLargeNum(int num1, int num2) {
    int temp1 = num1;
    int temp2 = num2;
    while (temp1 > 0 && temp2 > 0) {
        int n1 = temp1 % 10;
        int n2 = temp2 % 10;
        if (n1 > n2) {
            return num1;
        } else if (n1 < n2) {
            return num2;
        } else {
            temp1 /= 10;
            temp2 /= 10;
        }
    }
    return num1;
}

int main() {
    int num1, num2;

    cin >> num1 >> num2;

    int num = findLargeNum(num1, num2);

    while (num > 0) {
        cout << num % 10;
        num /= 10; 
    }
    cout << endl;
}