// Not Accepted
#include <stdio.h>
#include <string.h>

int main(void) {
    int N, m, k;

    while (scanf("%d%d%d", &N, &m, &k) == 3 && (N + m + k)) {
        int q[N];
        for (int i = 0; i < N; i++) {
            q[i] = 0;
        }
        int left = N;
        int off1 = -1;
        int off2 = N;
        
        while (left) {
            int cnt1 = m;
            int cnt2 = k;
            while (cnt1) {
                off1 = (1 + off1) % N;
                cnt1 -= (q[off1] == 0) ? 1 : 0;
            }

            while (cnt2) {
                off2 = (off2 - 1 + N) % N;
                cnt2 -= (q[off2] == 0) ? 1 : 0;
            }

            q[off1] = 1;
            q[off2] = 1;
            left--;
            if (off1 != off2) {
                printf("  %d  %d", off1, off2);
                left--;
            } else {
                if (left > 0) {
                    printf(" %d", off1);
                } else {
                    printf("  %d", off1);
                }
            }

            if (left > 0) {
                printf(",");
            }
            getchar();
        }
        printf("\n");
    }
    return 0;
}




