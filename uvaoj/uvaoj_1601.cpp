#include <iostream>
#include <cstdio>
#include <queue>
#inlcude <utility>
using namespace std;

const int maxw = 16 + 1;
const int maxh = 16 + 1;
const int maxn = 3 + 1;

int w, h, n;
int d[maxh][maxw][maxn]; /* steps need to reach the state */
char G[maxh][maxw];
pair<int, int> target[maxn];

struct State {
  pair<int, int> pos[maxn];
};


/* if we extract spaces to form a graph,
   we could enumerate by moving the white space inside the blocks,
   and check if that is valid or not
*/
bool in_pos(struct State state) {
  for (int i = 0; i < n ; i++) 
    if (state.pos[i] != target[i]) 
      return false;
  return true;
}


void solve() {
  int dy[4] = { 1, -1, 0, 0 };
  int dx[4] = { 0, 0, 1, -1 };
  queue<State> q;
  while (!q.empty()) {
    State state = q.front();
    if (in_pos(state)) {
      return;
    }
  }
  
  
}

int main(void) {
  while (scanf("%d%d%d", &w, &h, &n) == 3) {
    getchar();
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        scanf("%c", &G[i][j]);
      }
      getchar();
    }
    solve();
  }
  return 0;
}
