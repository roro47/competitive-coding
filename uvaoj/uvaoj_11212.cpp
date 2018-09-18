// Time limit exceeded

#include <iostream>
#include <deque>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <utility>
#include <cmath>
using namespace std;

deque<int> order;
const int maxn = 10;
int maxd = 8;
int min_d = INT_MAX;
map<pair<long, long>, int> m;
int n;
long id(deque<int> order) {
  long d = 0;
  for (int i = 0; i < n; i++) {
    d += order[i] * pow(10, n - i - 1);
  }
  return d;
}

int h(deque<int> order) {
  for (int i = 1; i < n; i++) {
    if (order[i] < order[i-1]) {
      return n - i;
    }
  }
  return 0;
}

void solve(deque<int> order, int d) {
  if (is_sorted(order.begin(), order.end())) {
    //  cout << "find d " << d << endl;
    min_d = min(min_d, d);
    //cout << "min_d: " << min_d << endl;
    return;
  }
  /*
  if (d >= maxd) {
    return;
  }
  */
  /*
  if (3*d + h(order) > 3*maxd ||
      d + h(order) > maxd ||
      d >= maxd ||
      d >= min_d) {
    return;
  }
  */
  if (3*d + h(order) > 3*maxd ||
      d >= maxd ||
      d >= min_d) {
    return;
  }
  
  for (int i = 0; i < n; i++) {
    /* iterate through the starting position to do the cut */
    for (int len = 1; i + len <= n; len++) {
      /* iterate the len to cut */
      if ((i && order[i-1] == order[i]-1) ||
          ((i+len-1) >= 0 &&
           (i+len) < n &&
           order[i+len-1] == order[i+len]-1) ||
          len == n) {
        continue;
      }
      deque<int> n_order = order;
      deque<int> moved(n_order.begin() + i, n_order.begin() + i + len);
      /*
      cout << "moved " << endl;
      for (auto c : moved) {
        cout << c << " ";
      }
      cout << endl;
      */
      n_order.erase(n_order.begin() + i, n_order.begin() + i + len);
      for (int j = 0; j <= n_order.size(); j++) {
        /* iterate the point to place the moved one */
        deque<int> nn_order = n_order;
        nn_order.insert(nn_order.begin() + j, moved.begin(), moved.end());
        if (!m.count(pair<long, long>(id(nn_order), d+1))  && (d+1) < min_d) {
          m[pair<long, long>(id(nn_order), d+1)] = 1;
          solve(nn_order, d+1);
        }
      }
    }
  }
}
        
  

int main(void) {
  int n_case = 1;
  while (scanf("%d", &n) == 1 && n) {
    m.clear();
    order.clear();
    min_d = INT_MAX;
    for (int i = 0; i < n; i++) {
      int d; scanf("%d", &d);
      order.push_back(d);
    }
    
    m[pair<long, long>(id(order), 0)] = 1;
    solve(order, 0);
    printf("Case %d: %d\n", n_case++, min_d);
  }
  return 0;
}
