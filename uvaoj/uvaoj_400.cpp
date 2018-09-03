// Accepted
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int main(void) {
    int n;
    string dash(60, '-');
    while (cin >> n) {
        string f;
        int max_len = 0;
        vector<string> vf;
        while (n--) {
            cin >> f; 
            if (f.size() > max_len) {
                max_len = f.size();
            }
            vf.push_back(f);
        }
        sort(vf.begin(), vf.end());
        int num_col = (60 - max_len) / (max_len + 2) + 1;
        
        int num_row;
        if (num_col == 0) {
            num_col = 1;
            num_row = vf.size();
        } else {
            num_row = vf.size() / num_col;
            if (vf.size() % num_col != 0) {
                num_row++;
            }
        }
        cout << dash << endl;
        for (int i = 0; i < num_row; i++) {
            for (int j = 0; j < num_col; j++) {
                int idx = j*num_row + i;
                if (idx < vf.size()) {
                    int pad_len;
                    if (num_col -1 == j) {
                        pad_len = max_len - vf[idx].size();
                    } else {
                        pad_len = max_len + 2- vf[idx].size();
                    }
                    string pad(pad_len, ' ');
                    cout << vf[idx] << pad;
                }
            }
            cout << endl;
        }
    }
    return 0;
}

