// Accepted
#include <iostream>
#include <set>
#include <cctype>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
    string s;
    set<string> dic;
    while (cin >> s) {
        string w;
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                s[i] = tolower(s[i]);
            } else {
                s[i] = ' ';
            }
        }
        stringstream ss(s);
        while (ss >> w) {
            dic.insert(w);

        }
    }

    auto begin = dic.begin();
    while (begin != dic.end()) {
        cout << *begin << endl;
        begin++;
    }
    return 0;
}

