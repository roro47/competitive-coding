#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100;

int n, l = maxn;
int S[maxn];
int cnt = 0;
int dfs(int cur) {
  if (cnt++ == l) {
    for (int i = 0; i < cur; i++) {
      printf("%c", 'A' + S[i]);
      if (i != l - 1) {
        if ((i+1) % 4 == 0) printf(" ");
        if ((i+1) % (16*4) == 0) printf("\n");
      }
    }
    printf("\n");
    printf("%d\n", cur);
    return 0;
  }
  for (int i = 0; i < n; i++) { /* try the char at the current position */
    S[cur] = i;
    int ok = 1;
    for (int j = 1; 2*j <= cur+1; j++) { /* check all possible length of postfix */
      int equal = 1;
      for (int k = 0; k < j; k++) { /* check if they are the same */
        if (S[cur-k] != S[cur-k-j]) {
          equal = 0;
          break;
        }
      }
      if (equal) { ok = 0; break; }
    }
    if (ok) if (!dfs(cur+1)) return 0;
  }
  return 1;
}
          

int main(void) {
  while (scanf("%d%d", &l, &n) == 2 && l && n) {
    cnt = 0;
    dfs(0);
  }
}
