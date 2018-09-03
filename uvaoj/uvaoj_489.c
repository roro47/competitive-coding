// Not Accepted
#include <stdio.h>
#include <string.h>

char word[1000];
char input[1000];
int win;
int lose;
int chance;
int left;


void guess(char c) {
    int bad = 1;

    for (int i = 0; i < strlen(word); i++)
        if (word[i] == c) { word[i] = ' '; bad = 0; left--; }

    chance -= bad;
    win = left == 0;
    lose = chance == 0;
}

int main(void) {
    int n;
    
    while (scanf("%d", &n)) {
        if (n == -1) {
            return 0;
        }
        
        printf("Round %d\n", n);

        memset(word, 0, 1000);
        memset(input, 0, 1000);

        scanf("%s", word);
        scanf("%s", input);

        win = 0;
        lose = 0;
        chance = 7;
        left = strlen(word);

        for (int i = 0; i < strlen(input); i++) {
            guess(input[i]);
            if (win || lose) {
                break;
            }
        }

        if (win) {
            printf("You win.\n");
        } else { 
            if (lose) {
                printf("You lose.\n");
            } else {
                printf("You chickened out.\n");
            }
        }
    }
    return 0;
}



/*#include <stdio.h>
#include <string.h>

#define MAX_WORD 100
int main(void) {
    int n = 0;

    while (scanf("%d", &n) && n != -1) {

        printf("Round %d\n", n);

        char word[MAX_WORD];
        memset(word, '\0', MAX_WORD);

        scanf("%s", word);

        char c = getchar(); // eat the newline
        int count = 0;
        int t_count = 0;
        while ((c = getchar()) != '\n' && count < 6) {
            char *p;
            char *wp = word;
            count += strchr(word, c) == NULL ? 1 : 0;
            while ((p = strchr(wp, c)) != NULL) {
                *p = ' ';
                wp = p + 1;
                t_count++;
            }
        }

        if (t_count == strlen(word)) {
            printf("You win.\n");
        } else {
            if (count < 6) {
                printf("You chickened out.\n");
            } else {
                printf("You lose.\n");
            }
        }
    }
    return 0;
}

*/
