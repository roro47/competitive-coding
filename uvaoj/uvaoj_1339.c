// Accepted
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

// Note:
// could use qsort in stdlib.h

int main(void) {
    while (true) {
        char s1[100];
        char s2[100];
        int alpha1[26];
        int alpha2[26];

        memset(alpha1, 0, 26*4);
        memset(alpha2, 0, 26*4);
        int r1 = scanf("%s", s1);
        int r2 = scanf("%s", s2);
        if (r1 != 1 || r2 != 1) {
            return 0;
        }

        char *s1p = s1;
        char *s2p = s2;

        while (*s1p != '\0') {
            alpha1[*s1p++ - 'A'] += 1;
            alpha2[*s2p++ - 'A'] += 1;
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (alpha1[i] == alpha2[j]) {
                    alpha2[j] = 0;
                    break;
                }
            }
        }

        char *stat = "YES\n";
        for (int i = 0; i < 26; i++) {
            if (alpha2[i] != 0) {
                stat = "NO\n";
                break;
            }
        }
        printf("%s", stat);
    }
    return 0;
}
