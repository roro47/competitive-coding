#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 52 + 10;
int G[maxn][maxn];
int visit[maxn];
int id(char a, char b) {
  if (a == '0' && b == '0') return 0;
  if (b == '+') return a - 'A' + 1;
  return a - 'A' + 26;
}

void add_edge(int n1, int n2) {
  G[n1][n2] = 1;
  G[n2][n1] = 1;
}

void reset() {
  for (int i = 0; i < maxn; i++) {
    visit[i] = 0;
    for (int j = 0; j < maxn; j++) {
      G[i][j] = 0;
    }
  }
}

int dfs(int n) {
  for (int i = 0; i < maxn; i++) {
    if (G[n][i]) {
      if (visit[i]) return 1;
      visit[i] = 1;
      return dfs(i);
    }
  }
}

int main(void) {
  int n;
  while (scanf("%d", &n) == 1) {
    reset();
    //cout << "n " << n << endl;
    int squares[n][4];
    for (int i = 0; i < n; i++) {
      getchar();
      for (int j = 0; j < 4; j++) {
        char a, b;
        scanf("%c%c", &a, &b);
        //cout << "a " << a << " b " << b << endl;
        squares[i][j] = id(a, b);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int connect = 0, kp1, kp2;
        for (int k1 = 0; k1 < 4 && !connect; k1++) {
          for (int k2 = 0; k2 < 4; k2++) {
            if (squares[i][k1] && 
                abs(squares[i][k1] - squares[j][k2]) == 26) {
              kp1 = k1; kp2 = k2;
              connect = 1; break;
            }
          }
        }

        if (connect) {
          for (int k1 = 0; k1 < 4; k1++) {
            for (int k2 = 0; k2 < 4; k2++) {
              if (k1 != kp1 && k2 != kp2) {
                int n1 = squares[i][k1], n2 = squares[j][k2];
                if (n1 && n2) {
                  add_edge(n1, n2);
                }
              }
            }
          }
        }
      }
    }
    int bounded = 0;
    for (int i = 0; i < maxn; i++) {
      if (dfs(i)) {
        bounded = 1; break;
      }
    }
    if (bounded) {
      cout << "bounded" << endl;
    } else {
      cout << "unbounded" << endl;
    }
    getchar();
  }
  return 0;
}

