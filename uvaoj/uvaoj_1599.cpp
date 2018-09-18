#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;
const int maxn = 100000;
const int maxm = 200000;
int n, m;
typedef vector<int> edges;
vector<vector<edges>> G;
int d[maxn];

void fill_d() {
  queue<int> q; q.push(n); d[n] = 0;
  while (!q.empty()) {
    int r = q.front(); q.pop();
    for (int i = 1; i <= n; i++) {
      if (G[r][i].size() && d[i] < 0) {
        q.push(i); d[i] = d[r] + 1;
      }
    }
  }
}


void find_ans() {
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int r = q.front();
    if (r == n) break;
    vector<int> next_nodes;
    int min = INT_MAX;
    for (int i = 1; i <= n; i++) {
      if (d[r] == d[i] + 1 && G[r][i].size()) {
        next_nodes.push_back(i);
        int min_ = *min_element(G[r][i].begin(), G[r][i].end());
        min = min_ < min ? min_ : min;
      }
    }
    for (auto n_node: next_nodes) {
      if (*min_element(G[r][n_node].begin(), G[r][n_node].end()) == min) {
        p[n_node] = r;
        q.push(n_node);
      }
    }
  }
  deque<int> ans_nodes;
  for (int i = n; i != 1;) {
    ans_nodes.push_front(i);
    i = p[i];
  }
  ans_nodes.push_front(1);
  cout << ans_nodes.size() << endl;
  for (int i = 0; i < ans_nodes.size(); i++) {
    cout << ans_nodes[i];
    if (i != ans_nodes.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
}

void reset() {
  G.clear();
  for (int i = 0; i < n; i++) {
    d[i] = -1;
  }
}

int main(void) {
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i <= n; i++) {
      vector<edges> v;
      for (int j = 0; j <= n; j++) {
        v.push_back(vector<int>());
      }
      G.push_back(v);
    }   
    for (int i = 0; i < m; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      G[a][b].push_back(c);
    }
    fill_d();
    find_ans();
  }
  return 0;
}

