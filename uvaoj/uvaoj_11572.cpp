// Accepted
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(void) {
  int n_case, n;
  cin >> n_case;
  while (n_case--) {
    cin >> n;
    map<long int, int> m;
    long int v[n];

    int l = 0, r = 0 , maxn = 1;
    for (; r < n; r++) {
      cin >> v[r];
      if (m.count(v[r]) && m[v[r]]) {
        maxn = max(maxn, r - l);
        for (; v[l] != v[r]; l++) {
          m[v[l]] = 0;
        }
        l++;
      } else {
        m[v[r]] = 1;
      }
    }
    maxn = max(maxn, r - l);
    
    if (n == 0) maxn = 0;
    
    cout << maxn << endl;
  }
  return 0;
}
