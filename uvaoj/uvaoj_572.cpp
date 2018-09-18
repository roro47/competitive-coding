// Accepted
#include <iostream>
#include <cstdio>
using namespace std;

const int num_max_m = 101;
const int num_max_n = 101;
char input[num_max_m][num_max_n];
int idx[num_max_m][num_max_n];
int cnt, m, n;
void reset() {
  for (int i = 0; i < num_max_m; i++) {
    for (int j = 0; j < num_max_n; j++) {
      idx[i][j] = -1;
      input[i][j] = '*';
    }
  }
  cnt = 0;
}

void dfs(int i, int j) {
  int di[8] = { 0, 0, 1, -1, 1, 1, -1, -1};
  int dj[8] = { 1, -1, 0, 0, 1, -1, 1, -1};
  for (int k = 0; k < 8; k++) {
    int i2 = di[k] + i, j2 = dj[k] + j;
    if (i2 < m && j2 < n && input[i2][j2] == '@' && idx[i2][j2] == -1) {
      idx[i2][j2] = cnt;
      dfs(i2, j2);
    }
  }
}

int main(void) {
  while (scanf("%d%d", &m, &n) == 2 && m) {
    getchar();
    reset();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%c", &(input[i][j]));
        idx[i][j] = -1;
      }
      getchar();
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (idx[i][j] == -1 && input[i][j] == '@') {
          idx[i][j] = cnt;
          dfs(i, j);
          cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
