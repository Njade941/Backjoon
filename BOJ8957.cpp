#include <iostream>
#include <string>
using namespace std;

int main() {
    int num;
    cin >> num;

    for(int i = 0; i < num; ++i) {
        string answer;
        cin >> answer;
        int score = 0;
        int contiScore = 1;
        for (auto pos = answer.begin(); pos != answer.end(); ++pos) {
            if (*pos == 'X') {
                contiScore = 1;
            } else {
                score += contiScore;
                contiScore++;
            }
        }
        cout << score << endl;
    }
}