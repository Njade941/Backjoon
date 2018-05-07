#include <iostream>
#include <string>
using namespace std;

void drawTri(int height, int x, int y, string* arr) {
	
	if (height == 3) {
		arr[y][x] = '*';
		arr[y - 1][x - 1] = '*';
		arr[y - 1][x + 1] = '*';
		arr[y - 2][x - 2] = '*';
		arr[y - 2][x - 1] = '*';
		arr[y - 2][x] = '*';
		arr[y - 2][x + 1] = '*';
		arr[y - 2][x + 2] = '*';
		return;
	}
	
	drawTri(height / 2, x, y, arr);
	drawTri(height / 2, x - height / 2, y - height / 2, arr);
	drawTri(height / 2, x + height / 2, y - height / 2, arr);
}



int main() {
	int line;
	cin >> line;
	string* arr = new string[line + 1];

	string temp = "";
	for (int i = 0; i < line * 2; ++i) {
		temp.append(" ");
	}

	for (int i = 0; i <= line; ++i) {
		arr[i] = temp;
	}

	drawTri(line, line, line, arr);

	for (int i = line; i > 0; --i) {
        arr[i].erase(arr[i].begin());
 		cout << arr[i] << '\n';
	}
    delete[]arr;
}