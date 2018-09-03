// Accepted
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main(void) {
    int N, Q, q, count = 1;
    while(scanf("%d%d", &N, &Q) == 2 && N && Q) {
         int m[N];
         for (int i = 0; i < N; i++) {
             scanf("%d", m + i);
         }
         sort(m, m+N);
         printf("CASE# %d:\n", count++);
         while (Q--) {
             scanf("%d", &q);
             int d = lower_bound(m, m+N, q) - m;
             if (m[d] == q) {
                 printf("%d found at %d\n", q, d+1);
             } else {
                 printf("%d not found\n", q);
             }
         }
    }
    return 0;
}
