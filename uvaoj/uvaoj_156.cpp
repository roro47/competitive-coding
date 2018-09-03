// Accepted
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main(void) {
    string s;
    map<string, int> m;
    vector<string> v;
    int count = 0;
    while (cin >> s) {
        if (s == "#") {
            break;
        }
        v.push_back(s);
        for (int i = 0; i < s.size(); i++) {
            s[i] = tolower(s[i]);
        }
        sort(s.begin(), s.end());
        if (m.find(s) != m.end()) {
            m[s] = -1;
        } else {
            m[s] = count;
        }
        count++;
    }
    vector<string> ans;
    for (auto begin = m.begin(); begin != m.end(); begin++) {
        if (begin->second != -1) {
            ans.push_back(v[begin->second]);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto begin = ans.begin(); begin != ans.end(); begin++) {
        cout << *begin << endl;
    }
    return 0;
}
    

        

        
