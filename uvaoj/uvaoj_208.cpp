// Accepted
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 21 + 1;

int G[maxn][maxn];
int m = maxn-1, f;
vector<vector<int>> paths;

void reset() {
  paths.clear();
  for (int i = 0; i <= m; i++) 
    for (int j = 0; j <= m; j++) 
      G[i][j] = 0;
}
        

void solve(vector<int> v) {
  if (v.size() && *(v.end()-1) == f) {
    paths.push_back(v);
    return;
  }
  for (int i = 2; i <= m; i++) {
    if (find(v.begin(), v.end(), i) == v.end()) {
      if (!v.size() || G[*(v.end() -1)][i]) {
        vector<int> nv = v;
        nv.push_back(i);
        solve(nv);
        
      }
    }
  } 
}

bool check(vector<int> v) {
  if (v.size() && *(v.end()-1) == 1) {
    return true;
  }
  for (int i = f; i >= 1; i--) {
    if (find(v.begin(), v.end(), i) == v.end()) {
      if (!v.size() || G[*(v.end()-1)][i]) {
        vector<int> nv = v;
        nv.push_back(i);
        if (check(nv)) return true;
      }
    }
  }
  return false;
}
        
int main(void) {
  int n_case = 1;
  while (scanf("%d", &f) == 1) {
    int a, b;
    reset();
    while (scanf("%d%d", &a, &b) == 2 && a && b) {
      G[a][b] = 1;
      G[b][a] = 1;
      m = max(max(a, b), m);
    }
    vector<int> v; v.push_back(1);
    vector<int> v2; v2.push_back(f);
    if (check(v2)) {  
      solve(v);
    }
    printf("CASE %d:\n", n_case++);
    for (int i = 0; i < paths.size(); i++) {
      for (int j = 0; j < paths[i].size(); j++) {
        printf("%d", paths[i][j]);
        if (j != paths[i].size() -1) {
          printf(" ");
        }
      }
      printf("\n");
    }
    /*
    for (auto p: paths) { 
      for (auto c: p) {
        printf("   %d", c);
      }
      printf("\n");
      }*/
    printf("There are %d routes from the firestation to streetcorner %d.\n", paths.size(), f);
  }
  return 0;
}
