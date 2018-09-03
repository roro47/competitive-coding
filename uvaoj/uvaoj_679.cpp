// Accepted
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(void) {
  int l, D, I;
  scanf("%d", &l);
  while (l--) {
    scanf("%d%d", &D, &I);
    int MAX_NODE = (int) pow(2, D) - 1;
    int MAX_LAYER_START;
    int k = 1;
    for (int i = 0; i < D - 1; i++) {
      if (I % 2) {
        k = 2*k;
        I = (I+1)/2;
      } else {
        k = 2*k + 1;
        I = I/2;
      }
    }
    printf("%d\n", k);
  }
  return 0;
}

    

    

/* actually simulate the movement upon the tree
 * is slower
int main(void) {
  int l, D, I;
  scanf("%d", &l);
  while (l--) {
    scanf("%d%d", &D, &I);
    int t[(int)pow(2, D)];
    int last_layer_start = pow(2, D - 1);
    for (int i = 0; i < pow(2, D); i++) {
      t[i] = 0;
    }
    int last = -1;
    while (I--) {
      int n = 1;
      while (n < last_layer_start) {
        t[n] = !t[n];
        if (t[n]) {
          n = 2 * n;
        } else {
          n = 2 * n + 1;
        }
      }
      last = n;
    }
    cout << last << endl;
  }
  scanf("%d", &I);
  return 0;
}
*/
