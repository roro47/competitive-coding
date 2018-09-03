// Not Accepted
#include <iostream>
#include <vector>
#include <cstdio>
#include <cassert>
#include <cstring>
using namespace std;

/* restore every block on top of a*/
void restore(vector<vector<int>> &v, int a) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (a == v[i][j]) {
                for (int k = v[i].size() - 1; k > j; k--) {
                    v[v[i][k]].push_back(v[i][k]);
                    v[i].pop_back();
                }
                return;
            }
        }
    }
}

void mov(vector<vector<int>> &v, int a, int b) {
    int d1 = 0, d2 = 0;
    bool found = false;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == a) {
                d1 = i;
                d2 = j;
                found = true;
                break;
            }
        }
    }
    assert(found);

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == b) {
                int c1 = v[d1].size();
                int a_end = d2; 
                for (; a_end < c1; a_end++) {
                    /*
                    if (v[d1][a_end] == b) {
                        break;
                    }
                    */
                    v[i].push_back(v[d1][a_end]);
                }
                v[d1].erase(v[d1].begin() + d2, v[d1].begin() + a_end);
                return;
            }
        }
    }
}

bool match(char *c1, const char *c2) {
    return strcmp(c1, c2) == 0;
}

int main(void) {
    int n;
    scanf("%d", &n);
    vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
        vector<int> v2 = {i};
        v.push_back(v2);
    }

    char c1[5] = {0};
    char c2[5] = {0};
    int a, b;


    while (scanf("%s%d%s%d", c1, &a, c2, &b) == 4) {
        cout << c1 << " " << a << " " << c2 << b << endl;
        if (match(c1, "move")) {
            restore(v, a);
        } 

        if (match(c2, "onto")) {
            restore(v, b);
            mov(v, a, b);
        } else {
            mov(v, a, b);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int k = 0; k < v[i].size(); k++) {
            printf(" %d", v[i][k]);
        }
        printf("\n");
    }
    return 0;
}
