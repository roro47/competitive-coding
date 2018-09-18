// Accepted
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
int n_case, n, n_node, cnt, odd;
int G[26][26];
int visit[26], in[26];
int count[26];

void reset() {
  for (int i = 0; i < 26; i++) {
    visit[i] = 0; count[i] = 0; in[i] = 0;
    for (int j = 0; j < 26; j++) {
      G[i][j] = 0;
    }
  }
  cnt = 0;
  odd = 0;
  n_node = 0;
}

void dfs(int i) {
  for (int j = 0; j < 26; j++) {
    if (G[i][j] && !visit[j]) {
      visit[j] = 1;
      dfs(j);
      cnt++;
    }
  }
}
  

int main(void) {
  string s;
  scanf("%d", &n_case); getchar();
  while (n_case--) {
    reset();
    scanf("%d", &n); getchar();
    int start = -1;
    while (n--) {
      cin >> s;
      int f = s[0] - 'a';
      int t = s[s.size() - 1] - 'a';
      start = f;
      if (!in[f]) { in[f] = 1; n_node++; }
      if (!in[t]) { in[t] = 1; n_node++; }
      G[f][t] = 1; G[t][f] = 1;
      count[f]--; count[t]++;
    }

    // check for connectivity
    dfs(start);

    // check for degree for node
    int ok = 1;
    vector<int> odds;
    for (int i = 0; i < 26; i++) {
      if (count[i] != 0) {
        odds.push_back(count[i]);
      } 
    }

    if (odds.size() > 2) {
      ok = 0;
    } else if (odds.size() == 2) {
      ok = (odds[0] == 1 && odds[1] == -1) ||
           (odds[0] == -1 && odds[1] == 1);
    }
   
    if (cnt != n_node || !ok) 
      cout << "The door cannot be opened." << endl;
      else 
      cout << "Ordering is possible." << endl;
  }
  return 0;
}
