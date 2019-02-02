#include <iostream>
#include <vector>
using namespace std;

bool alpha[26] = { false, };
int L, C;
int vowels[] = { 0, 4, 8, 14, 20 };

void Possible(vector<int>& cipher) {
    int vowel = 0;
    int consonant = 0;

    for (auto it = cipher.begin(); it < cipher.end(); it++) {
        int i = *it;
        bool check = false;
        for (int j = 0; j < 5; j++) {
            if (i == vowels[j]) {
                vowel++;
                check = true;
            }
        }
        if (!check) {
            consonant++;
        }
    }

    if (vowel > 0 && consonant > 1) {
        for (auto it = cipher.begin(); it < cipher.end(); it++) {
            cout << char(*it + 'a');
        }
    }
    else {
        return;
    }
    cout << endl;
}

void Solve(int c, vector<int>& cipher) {
    if (cipher.size() == L) return Possible(cipher);

    for (int i = c; i < 26; i++) {
        if (alpha[i]) {
            cipher.push_back(i);
            Solve(i+1, cipher);
            cipher.pop_back();
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        char c;
        cin >> c;
        alpha[c-'a'] = true;
    }

    vector<int> cipher;
    Solve(0, cipher);

}