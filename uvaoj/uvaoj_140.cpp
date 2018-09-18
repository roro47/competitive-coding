// Accepted
// clean
#include <iostream>
#include <string>
#include <climits>
#include <sstream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 26 + 10;
int G[maxn][maxn];
int S[maxn];
int visit[maxn];
int n_nodes;
vector<int> candidates;
int k = INT_MAX;
string ans;
int id(char c) { return c  - 'A'; }

void reset() {
  candidates.clear();
  n_nodes = 0;
  ans = string();
  k = INT_MAX;
  for (int i = 0; i < maxn; i++) {
    S[i] = 0;
    visit[i] = 0;
    for (int j = 0; j < maxn; j++) {
      G[i][j] = 0;
    } 
  }
}


int calculate(int cur) {
  int cur_k = 0;
  for (int i = 0; i < cur; i++) {
    for (int j = i + 1; j < cur; j++) {
      if (G[S[i]][S[j]]) {
        if (j - i > k) {
          return 0;
        }
        cur_k = cur_k < (j - i) ? (j - i) : cur_k; 
      }
    }
  }
  if (cur_k && cur == n_nodes) {
    k = k < cur_k ? k : cur_k;
  }
  return 1;
}

void dfs(int cur) {
  if (cur == n_nodes) {
    int old_k = k;
    calculate(cur);
    if (old_k > k) {
      ans = string();
      for (int i = 0; i < n_nodes; i++) {
        ans.push_back((char)(S[i] + 'A'));
      }

    }
    return;
  }
  for (int i = 0; i < candidates.size(); i++) {
    int ok = 1;
    for (int j = 0; j < cur && ok; j++) 
      if (S[j] == candidates[i]) ok = 0;
    if (ok) {
      S[cur] = candidates[i];
      //if (cur && !G[S[cur]][S[cur-1]]) continue;
      if (k != INT_MAX) {
        if (calculate(cur)) {
          /* search under this branch iff this could be the possible answer */
          dfs(cur + 1);
        }
      } else {
        dfs(cur + 1);
      }
    }
  }   
}

      
int main(void) {
  string line;
  while (getline(cin, line) && line[0] != '#') {
    reset();
    stringstream ss(line);
    char p, filter, c;
    while (ss >> p) {
      ss >> filter; assert(filter == ':');
      if (!visit[id(p)]) {
        candidates.push_back(id(p));
        visit[id(p)] = 1;
        n_nodes++;
      }
      while (ss >> c && c != ';') {
        if (isspace(p) || isspace(c)) {
          assert(false);
        }
        G[id(p)][id(c)] = 1;
        G[id(c)][id(p)] = 1;
        if (!visit[id(c)]) {
          candidates.push_back(id(c));
          visit[id(c)] = 1;
          n_nodes++;
        }
      }
    }
    sort(candidates.begin(), candidates.end());
    dfs(0);
    for (int i = 0; i < n_nodes; i++) {
      printf("%c ", ans[i]);
    }
    if (k == INT_MAX) {
      k = 1;
    }
    printf("-> %d\n", k);
  }
  return 0;
}
