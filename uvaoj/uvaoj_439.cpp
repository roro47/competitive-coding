// Accepted
#include <iostream>
#include <queue>
#include <utility>
#include <cstdio>
using namespace std;
const int maxn = 8;
int d[maxn][maxn];
bool inside(int x) {
  return x < 8 && x >= 0;
}
void reset() {
  for (int i = 0; i < maxn; i++) 
    for (int j = 0; j < maxn; j++) 
      d[i][j] = -1;
}

void solve(int x0, int y0, int x1, int y1) {
  int dx[8] = { -1, 1, 2, 2,  1, -1, -2, -2 };
  int dy[8] = {  2, 2, 1, -1, -2, -2, -1, 1 };
  queue<pair<int, int>> q;
  q.push(pair<int, int>(x0,y0));
  d[y0][x0] = 0;
  while (!q.empty()) {
    pair<int, int> p = q.front(); q.pop();
    if (p.first == x1 && p.second == y1) {
      printf("To get from %c%d to %c%d takes %d knight moves.\n",
          'a' + x0, y0+1, 'a' + x1, y1+1, d[p.second][p.first]);
      return;
    }
    for (int i = 0; i < 8; i++) {
        pair<int, int> np = p;
        np.first += dx[i]; np.second += dy[i];
      if (inside(np.first) && inside(np.second) && d[np.second][np.first] < 0) {
        d[np.second][np.first] = d[p.second][p.first] + 1;
        q.push(np);
      }
    }
  }
}
  

int main(void) {
  char from[5], to[5];
  while (scanf("%s%s", from, to) == 2) {
    reset();
    int x0, y0, x1, y1;
    x0 = from[0] - 'a';
    y0 = from[1] - '1';
    x1 = to[0] - 'a';
    y1 = to[1] - '1';
    solve(x0, y0, x1, y1);
  }
  return 0;
}
