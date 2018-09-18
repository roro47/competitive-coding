#include <iostream>
#include <cstdio>
#include <queue>
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <climits>
#include <utility>
using namespace std;
const int maxn = 400;
int G[maxn+1][maxn+1];
int d[maxn+1][maxn+1][maxn+1];
int m = maxn, n = maxn, k = maxn;
struct State {
  int x;
  int y;
  int k;
  State(): x(-1), y(-1), k(-1) {}
  State(int x_, int y_, int k_): x(x_), y(y_), k(k_) {}
};

void reset(int m, int n) {
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      G[i][j] = 0;
      for (int k1 = 0; k1 <= k; k1++) {
        d[i][j][k1] = -1;
      }
    }
  }
}


bool inside(int y, int x) {
  return x >= 1 && x <= n && y >= 1 && y <= m;
}


void solve() {
  int dx[4] = { 0, 0, 1, -1 };
  int dy[4] = { 1, -1, 0, 0};
  queue<struct State> q;
  q.push(State(1, 1, k));
  d[1][1][k] = 0;
  while (!q.empty()) {
    struct State p = q.front();
    if (p.y == m && p.x == n) {
      printf("%d\n", d[p.y][p.x][p.k]);
      return;
    }
    q.pop();
    for (int i = 0; i < 4; i++) {
      struct State np = p;
      np.x += dx[i]; np.y += dy[i];
      if (G[np.y][np.x]) {
        if (p.k) {
          np.k = np.k - 1;
        } else {
          continue;
        }
      } else {
        np.k = k;
      }
      if (inside(np.y, np.x) && d[np.y][np.x][np.k] < 0) {
        //cout << "y " << np.y << " x " << np.x << " k " << np.k << endl;
        d[np.y][np.x][np.k] = d[p.y][p.x][p.k] + 1;
        q.push(np);
      }
    }
  }
  printf("%d\n",  -1);
}

int main(void) {
  int n_case;
  scanf("%d", &n_case);
  while (n_case--) {
    reset(m, n);
    scanf("%d%d", &m, &n);
    scanf("%d", &k);
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &G[i][j]);
      }
    }
    solve();
  }
  return 0;
}
