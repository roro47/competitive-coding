// Accepted
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void) {
  int t, n, x, y;

  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int num_id = 0;
    vector<vector<int>> v_figure;
    vector<vector<int>> h_figure;
    map<int, int> idx = map<int, int>();
    while (n--) {
      scanf("%d%d", &x, &y);
      if (!idx.count(y)) {
        idx[y] = num_id++;
        v_figure.push_back(vector<int>());
      }
      v_figure[idx[y]].push_back(x);
    }

    for (int i = 0; i < v_figure.size(); i++) {
      sort(v_figure[i].begin(), v_figure[i].end());
    }

    bool foldable = true;

    double init = 10001;
    double middle = 10001;

    for (int i = 0; i < v_figure.size() && foldable; i++) {
       
      while (v_figure[i].size() > 1) {
        double left = *v_figure[i].begin();
        double right = *(v_figure[i].end() - 1);
        if (middle == init) {
          middle = left + (right - left) / 2;
        } else {
          if (middle != (left + (right - left) / 2)) {
            foldable = false;
            break;
          }
        }
        v_figure[i].pop_back();
        v_figure[i].erase(v_figure[i].begin());
      }
      if (v_figure[i].size() == 1) {
        if (middle == init) {
          middle = v_figure[i][0];
        } else {
          foldable = middle == ((double)v_figure[i][0]);
        }
      }
    }

    if (foldable) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
