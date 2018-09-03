// Accepted
#include <iostream>
#include <set>
#include <stack>
#include <map>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

typedef set<int> Set;
map<Set, int> id;
stack<int> set_stack;
vector<Set> Setcache;
int num_id = 0;

int ID(Set s) {
    if (id.count(s)) {
        return id[s];
    }
    id[s] = num_id++;
    Setcache.push_back(s);
    return id[s];
}

int main(void) {
    int t, n;
    string c;
    scanf("%d", &t);
    while (t--) {
        num_id = 0;
        Setcache.clear();
        id.clear();
        scanf("%d", &n);
        while (n--) {
            cin >> c;
            if (c[0] == 'P') {
                set_stack.push(ID(Set()));
            } else if (c[0] == 'D') {
                set_stack.push(set_stack.top());
            } else {
                Set top1 = Setcache[set_stack.top()]; set_stack.pop();
                Set top2 = Setcache[set_stack.top()]; set_stack.pop();
                Set s;
                if (c[0] == 'U') {
                    set_union(top1.begin(), top1.end(),
                              top2.begin(), top2.end(),
                              inserter(s, s.begin()));
                    set_stack.push(ID(s));
                } else if (c[0] == 'I') {
                    set_intersection(top1.begin(), top1.end(),
                                     top2.begin(), top2.end(),
                                     inserter(s, s.begin()));
                    set_stack.push(ID(s));
                } else if (c[0] == 'A') {
                    top2.insert(ID(top1));
                    set_stack.push(ID(top2));
                } else {
                    assert(false);
                }

            }
            cout << Setcache[set_stack.top()].size() << endl;
        }
        cout << "***" << endl;
    }
    return 0;
}
