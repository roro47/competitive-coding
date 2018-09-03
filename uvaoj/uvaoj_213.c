// Accepted
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
char c;
bool term;

int bin_to_int(char *p, int len) {
    int n = 0;
    for (int i = 0; i < len; i++) {
        n += (*(p + (len - i - 1)) - '0') * pow(2, i);
    }
    return n;
}

int get_idx(char *bin, int len) {
    int val = bin_to_int(bin, len);
    int idx = pow(2, len) - 1 - (len - 1) + val;
    return idx;
}

void readbuffer(char *buffer, int len) {
    for (int i = 0; i < len;) {
        c = getchar();
        if (c == EOF) {
            term = true;
            return;
        }
        if (c != '\n' && c != '\r') {
            buffer[i] = c;
            i++;
        }
    }
}

int main(void) {
    c = 1;
    term = false;
    char header[1000];
    char buffer[1000];
    while (!term) {
        memset(header, '\0', 1000);
        fgets(header, 1000, stdin);
        header[strlen(header) - 1] = '\0';

        int len = 1;

        // update mapping
        while (len) {

            // get len
            memset(buffer, '\0', 1000);
            readbuffer(buffer, 3);
            if (term) {
                return 0;
            }
            len = bin_to_int(buffer, 3);
            
            // decode
            while (true) {
                memset(buffer, '\0', 1000);
                readbuffer(buffer, len); 
                if (bin_to_int(buffer, len) == (pow(2, len) - 1)) {
                    break;
                }
                printf("%c", header[get_idx(buffer, len) - 1]);
                
            }
       
        }
        printf("\n");
        if (term) {
            return 0;
        }
        c = getchar();
    }
            
    return 0;
}
