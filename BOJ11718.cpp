#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main () {
    string s;
    vector<string> vec;
    while (getline (cin, s)) {
        vec.push_back(s);
    }

    copy(vec.begin(),
         vec.end(),
         ostream_iterator<string> (cout, "\n"));
}