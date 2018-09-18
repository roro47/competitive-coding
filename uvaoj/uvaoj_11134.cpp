// Not Accepted
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
int n;
vector<pair<int, int>> h_ranges;
vector<pair<int, int>> v_ranges;
vector<int> h_sort;
vector<int> v_sort;

struct {
  bool operator()(int a, int b) {
    return h_ranges[a] < h_ranges[b];
  }
} h_less;

struct {
  bool operator()(int a, int b) {
    return v_ranges[a] < v_ranges[b];
  }
} v_less;


int main(void) {
  while (scanf("%d", &n) == 1 && n) {
    h_ranges.clear();
    v_ranges.clear();
    h_sort.clear();
    v_sort.clear();
    for (int i = 0; i < n; i++) {
      int xl, xr, yl, yr;
      scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
      h_ranges.push_back(pair<int,int>(xl, xr));
      v_ranges.push_back(pair<int,int>(yl, yr));
      h_sort.push_back(i); v_sort.push_back(i);
    }
    sort(h_sort.begin(), h_sort.end(), h_less);
    sort(v_sort.begin(), v_sort.end(), v_less);
    /*

    for (auto p: h_sort) {
      cout << h_ranges[p].first << " " << h_ranges[p].second << endl;
    }
    cout << endl;
    for (auto p: v_sort) {
      cout << v_ranges[p].first << " " << v_ranges[p].second << endl;
    }
    */
    
    vector<int> x_coord;
    vector<int> y_coord;
    map<int, int> x_idx;
    map<int, int> y_idx;
    bool valid = true;
    for (int i = 0; i < n; i++) {
      x_idx[h_sort[i]] = i;
      y_idx[v_sort[i]] = i;
      pair<int, int> px = h_ranges[h_sort[i]];
      pair<int, int> py = v_ranges[v_sort[i]];
      int xl = px.first; int yl = py.first;
      if (!x_coord.empty()) {
        if (x_coord[i-1] >= xl) {
          if (px.second < x_coord[i-1]) {
            valid = false; break;
          } else { xl = x_coord[i-1] + 1; }
        }
      }
      if (!y_coord.empty()) {
        if (y_coord[i-1] >= yl) {
          if (py.second < y_coord[i-1]) {
            valid = false; break;
          } else { yl = y_coord[i-1] + 1; }
        }
      }
      x_coord.push_back(xl);
      y_coord.push_back(yl);
    }
    if (valid) {
      for (int i = 0; i < n; i++) {
        printf("%d %d\n", x_coord[x_idx[i]], y_coord[y_idx[i]]);
      }
    } else {
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}
