// Not Accepted
// Runtime error
// Idea:
// create a table that stores the link
// to the new position
// create a table that is updated after every command

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 50
#define INVALID -1
enum Command {
    DC,
    DR,
    IC,
    IR,
    EX
};

int xs[MAX_SIZE*MAX_SIZE];
int ys[MAX_SIZE*MAX_SIZE];
int spreadsheet[MAX_SIZE][MAX_SIZE]; // store thr indexes of the cells
int n, r, c;
int R, C;

void print_spreadsheet() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%3d ", spreadsheet[i][j]);
        }
        printf("\n");
    }
    printf("====================================================\n");
}

void init() {
    /*
    memset(xs, 0xff, MAXSIZE*MAXSIZE*4);
    memset(ys, 0xff, MAXSIZE*MAXSIZE*4);
    memset(spreadsheet, 0xff, MAXSIZE*MAXSIZE*4);
    */
    int c = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0;  j < MAX_SIZE; j++) {
            spreadsheet[i][j] = INVALID;
            xs[c] = INVALID;
            ys[c] = INVALID;
            c++;
        }
    }
    //print_spreadsheet();
}


enum Command get_command(char *s) {
    if (strcmp(s, "DC") == 0) return DC;
    if (strcmp(s, "DR") == 0) return DR;
    if (strcmp(s, "IC") == 0) return IC;
    if (strcmp(s, "IR") == 0) return IR;
    if (strcmp(s, "EX") == 0) return EX;
    assert(false);
}

void get_args(int *args, int n_args) {
    while (n_args--) {
        int a;
        scanf("%d", &a);
        *args = a - 1; // to match the index
        args++;
    }
}

void exec_DC(int *args, int n_args) {
    int i = 1;
    while (n_args--) {
        for (int y = 0; y < r; y++) {
            int idx = spreadsheet[y][*args];
            if (idx >= 0) {
                xs[idx] = INVALID;
                ys[idx] = INVALID;
            }
            for (int x = *args; x < c; x++) {
                spreadsheet[y][x] = spreadsheet[y][x+1];
                idx = spreadsheet[y][x+1];
                if (idx >= 0) {
                    xs[idx] -= 1;
                }
                spreadsheet[y][x+1] = INVALID;
            }
        }
        c--;
        args++;
        *args -= i;
        i++;
    }
    //print_spreadsheet();
}


void exec_DR(int *args, int n_args) {
    int i = 1;
    while (n_args--) {
        for (int x = 0; x < c; x++) {
            int idx = spreadsheet[*args][x];
            if (idx >= 0) {
                xs[idx] = INVALID;
                ys[idx] = INVALID;
            }
            for (int y = *args; y < r; y++) {
                spreadsheet[y][x] = spreadsheet[y+1][x];
                idx = spreadsheet[y+1][x];
                if (idx >= 0) {
                    ys[idx] -= 1;
                }
                spreadsheet[y+1][x] = INVALID;
            }
        }
        r--;
        args++;
        *args -= i;
        i++;
    }
    //print_spreadsheet();
}

void exec_IC(int *args, int n_args) {
    int i = 1;
    while (n_args--) {
        for (int y = 0; y < r; y++) {
            for (int x = c - 1; x >= *args; x--) {
                int idx = spreadsheet[y][x];
                if (idx >= 0) {
                    xs[idx]++;
                }
                spreadsheet[y][x+1] = spreadsheet[y][x];
            }
            spreadsheet[y][*args] = INVALID;
        }
        c++;
        args++;
        *args += i;
        i++;
    }
    //print_spreadsheet();
}

void exec_IR(int *args, int n_args) {
    int i = 1;
    while (n_args--) {
        for (int x = 0; x < c; x++) {
            for (int y = r - 1; y >= *args; y--) {
                int idx = spreadsheet[y][x];
                if (idx >= 0) {
                    ys[idx]++;
                }
                spreadsheet[y+1][x] = spreadsheet[y][x];
            }
            spreadsheet[*args][x] = INVALID;
        }
        r++;
        args++;
        *args += i;
        i++;
    }
    //print_spreadsheet();
}
                    
void exec_EX(int *args, int n_args) {
    int idx1 = spreadsheet[*args][*(args+1)];
    int idx2 = spreadsheet[*(args+2)][*(args+3)];
    int tmp;

    spreadsheet[*(args+2)][*(args+3)] = idx1;
    spreadsheet[*args][*(args+1)] = idx2;

    tmp = xs[idx1];
    xs[idx1] = xs[idx2];
    xs[idx2] = tmp;

    tmp = ys[idx1];
    ys[idx1] = ys[idx2];
    ys[idx2] = tmp;

    //print_spreadsheet();
}

int main(void) {

    int spreadsheet_num = 1;
    while (scanf("%d%d", &r, &c) == 2) {
        if (!r || !c) {
            return 0;
            break;
        }
        C = c;
        R = r;
        int count = 0;
        scanf("%d", &n);
        init();
        for (int y = 0; y < r; y++) {
            for (int x = 0; x < c; x++) {
                // assign the original indexes
                xs[count] = x;
                ys[count] = y;
                // init cells
                spreadsheet[y][x] = count;
                count++;
            }
        }

        while (n--) {
            char s[100];
            int args[MAX_SIZE];
            scanf("%s", s);

            enum Command command = get_command(s);
            int n_args;
            switch (command) {
                case DC:
                case DR:
                case IC:
                case IR:
                    scanf("%d", &n_args);
                    get_args(args, n_args);
                    break;
                case EX:
                    get_args(args, 4);
                    break;
                default:
                    assert(false);
            }

            switch (command) {
                case DC:
                    exec_DC(args, n_args);
                    break;
                case DR:
                    exec_DR(args, n_args);
                    break;
                case IC:
                    exec_IC(args, n_args);
                    break;
                case IR:
                    exec_IR(args, n_args);
                    break;
                case EX:
                    exec_EX(args, n_args);
                    break;
                default:
                    assert(false);
            }
        }

        int n_q;
        scanf("%d", &n_q);

        printf("Spreadsheet #%d\n", spreadsheet_num);
        while (n_q--) {
            int q_r, q_c;
            scanf("%d%d", &q_r, &q_c);
            int idx = (q_r - 1)* C + q_c -1;
            printf("Cell data in (%d,%d) ", q_r, q_c);
            if (ys[idx] >= 0 && xs[idx] >= 0 && spreadsheet[ys[idx]][xs[idx]] >= 0) {
                printf("moved to (%d,%d)\n", ys[idx] + 1, xs[idx] + 1);
            } else {
                printf("GONE\n");
            }
        }
        spreadsheet_num++;
        
    }
    return 0;
}
