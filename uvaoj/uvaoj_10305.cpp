// Accepted
#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;

const int max_n = 100;

int graph[max_n][max_n];
int visit[max_n];
int m, n;
deque<int> d;

void reset() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      graph[i][j] = 0;
    }
    visit[i] = 0;
  }
  d.clear();
}

void dfs(int i) {
  for (int j = 1; j <= n; j++) {
    if (graph[i][j]) {
      if (!visit[j]) {
        visit[j] = 1;
        dfs(j);
        d.push_front(j);
      }
    } 
  }
}
      
int main(void) {
  for (int i = 0; i < max_n; i++) {
    for (int j = 0; j < max_n; j++) {
      graph[i][j] = 0;
    }
  }

  while (scanf("%d%d", &n, &m) == 2 && n) {
    //cout << "n " << n << " m " << m  << endl;
    reset();
    int x, y;
    while (m--) {
      scanf("%d%d", &x, &y);
      //cout << "x " << x << " y " << y << endl;
      graph[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
      if (!visit[i]) {
        visit[i] = 1;
        dfs(i);
        d.push_front(i);
      }
    }
    for (int i = 0; i < d.size(); i++) {
      cout << d[i];
      if (i != d.size() - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
        
