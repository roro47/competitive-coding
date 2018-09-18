#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cassert>
using namespace std;

int n, s1, v1, s2, v2;
int main(void) {
  int n_case;
  scanf("%d", &n_case);
  for (int i = 0; i < n_case; i++) {
    scanf("%d%d%d%d%d", &n, &s1, &v1, &s2, &v2);
    int n1 = 0, n2 = 0;
    long long v = 0;
    long long prev_v = 0;
    if (n / v1 < n / v2) {
      while (n1 * s1 <= n) {
        n2 = (n - n1 *s1) / s2;
        assert((n2 *s2 + n1 * s1) <= n);
        v = max((long long)(n1*v1+ n2*v2), v);
        
        if (v < prev_v) {
          break;
        }
        
        prev_v = v;
        n1++;
      }
    } else {
      while (n2 * s2 <= n) {
        n1 = (n - n2 * s2) / s1;
        assert((n2 *s2 + n1 * s1) <= n);
        v = max((long long )(n1 *v1 + n2 *v2), v);
        /*
        if (v < prev_v) {
          break;
        }
        */
        prev_v = v;
        n2++;
      }
    }
    printf("Case #%d: %lld\n", i + 1, v);
  }
  return 0;
}
