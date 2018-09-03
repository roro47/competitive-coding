// Not Accepted : Wrong Answer
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <cstdio>
using namespace std;

vector<string> data_cache;
map<string, int> id_cache;

int ID(string s) {
    if (id_cache.count(s)) {
        return id_cache[s];
    }
    data_cache.push_back(s);
    id_cache[s] = data_cache.size() - 1;
    return id_cache[s];
}

int main(void) {
    int n, m;
    
    while (scanf("%d%d", &n, &m) == 2) {
        getchar();
        data_cache.clear();
        id_cache.clear();
        string line;
        int database[n][m];
        for (int r = 0; r < n; r++) {
            string s;
            char chr;
            int c = 0;
            while (scanf("%c", &chr)) {
                if (chr == '\n') {
                    database[r][c] = ID(s);
                    break;
                }
                if (chr == ',') {
                    database[r][c] = ID(s);
                    c++;
                    s.clear();
                    continue;
                }
                s.push_back(chr);
            }
        }
        bool find = false;
        for (int c1 = 0; c1 < m && !find; c1++) {
            for (int c2 = c1 + 1; c2 < m && !find; c2++) {
                map<pair<int, int>, int> pairs;
                for (int r2 = 0; r2 < n; r2++) {
                    pair<int, int> p(database[r2][c1], database[r2][c2]);
                    if (pairs.count(p)) {
                        int r1 = pairs[p];
                        find = true;
                        cout << "NO" << endl;
                        cout << r1 + 1 << " " << r2 + 1 << endl;
                        cout << c1 + 1 << " " << c2 + 1 << endl;
                        break;
                    }
                    pairs[p] = r2;
                }
            }
        }
        
        if (!find) {
            cout << "YES" << endl;
        }
        getchar();
    }
    return 0;
}
