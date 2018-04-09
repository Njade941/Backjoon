#include <iostream>

using namespace std;
void FindSelfNumber(bool* checkArray, int& i);
void print(bool* checkArray);
int CalDNum(int& num);

int main() {
	bool arr[10001] = { false, };
	for (int i = 1; i < 10001; ++i) {
		FindSelfNumber(arr, i);
	}
	print(arr);
}

void FindSelfNumber(bool* checkArray, int& num) {
	int i = num ;
	while (i < 10001) {
		if (!checkArray[i] || i != num) {
			i = CalDNum(i) ;
			if ( i < 10001 )
				checkArray[i] = true ;
		} else {
			i = 10001 ;
		}
	}
}

int CalDNum(int& num) {
	int result = num ;
	while(num > 0) {
		result += num % 10 ;
		num /= 10 ;
	}
	return result ;
}

void print(bool* checkArray) {
	for (int i = 1 ; i < 10001 ; ++ i) {
		if (!checkArray[i])
			cout << i << endl ;
	}
}