#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
const int maxp = 500+10;
int ps[maxp];
int m, k;
int solve(double val) {
   int part_sum = 0, count = 0, ok = 1;
      for (int i = m-1; i >= 0; i--) {
        part_sum += ps[i];
        if (part_sum == val) {
          part_sum = 0;
          count++;
        } else if (part_sum > val) {
          if (i == m-1) { ok = 0; break; }
          part_sum = ps[i+1];
          count++;
        }
        if (count > k) { ok = 0; break; }
      }
      
int main(void) {
  int n_case; cin >> n_case;
  while (n_case--) {
    cin >> m >> k;
    int sum = 0;
    for (int i = 0; i < m; i++) {
      cin >> ps[i]; sum += ps[i];
    }
    int val = sum/2;
    while (!solve(val)) {
      val += (sum - val)/2;
    }
    while (solve(val)) {
      val -= (sum - val)/2;
    }
    deque<int> ans;
    int partial_sum = 0, count = 0;
    for (int i = m-1; i >= 0; i--) {
      partial_sum += ps[i];
      if (partial_sum == val) {
        partial_sum = 0; count++; ans.push_front(i);
      } else if (partial_sum > val) {
        partial_sum = ps[i+1]; count++; ans.push_front(i);
      }
    }
    for (int i = 0, j = 0; i < m; i++) {
      if (i == ans[j]) { cout << "/ "; j++; }
      cout << ps[i];
      if (i != m - 1) cout << " ";
    }
  }
  return 0;
}
