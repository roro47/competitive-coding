#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int m[29][7];
int G[7][8];
int sol[7][8];
int used[29];
int n_sol = 0;

void init() {
  int count = 1;
  memset(used, '\0', 29*sizeof(char));
  for (int i = 0; i <= 6; i++) {
    for (int j = i; j <= 6; j++) {
      m[count++][j] = 1;
    }
  }
  count = 1;
  for (int i = 0; i <= 6; i++) {
    for (int j = 6-i+1; j > 0; j--) {
      m[count++][i] = 1;
    }
  }
  
}     
     
void reset() {
  n_sol = 0;
}

void print_sol() {
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 8; j++) {
      printf("  %2d", sol[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

void solve(int r, int c) {
  if (c > 7) { r++; c %= 8; }
  if (r >= 7) { print_sol(); n_sol++; return; }
  while (sol[r][c] != 0) {
    c++;
    if (c > 7) { r++; c %= 8;}
    if (r >= 7) {
      print_sol();
      n_sol++;
      return;
    }
  }
  
  int h1 = -1, h2 = -1, v1 = -1, v2 = -1;
  if (c <= 6 && !sol[r][c] && !sol[r][c+1]) {
    h1 = G[r][c]; h2 = G[r][c+1];
  }
  if (r <= 5 && !sol[r][c] && !sol[r+1][c]) {
    v1 = G[r][c]; v2 = G[r+1][c];
  }
  if (h1 == -1 && v1 == -1) {
    return;
  }
  for (int i = 1; i <= 28; i++) {
    if (!used[i]) {
      if (h1 != -1 && h2 != -1) {
        /* try to lay it horizontally*/
        if (m[i][h1] && m[i][h2]) {
          used[i] = 1; sol[r][c] = i; sol[r][c+1] = i;
          solve(r, c+2);
          used[i] = 0; sol[r][c] = 0; sol[r][c+1] = 0;
        }
      }
      if (v1 != -1 && v2 != -1) {
        /* try to lay it vertically*/
        if (m[i][v1] && m[i][v2]) {
          used[i] = 1; sol[r][c] = i; sol[r+1][c] = i;
          solve(r, c+1);
          used[i] = 0; sol[r][c] = 0; sol[r+1][c] = 0;
        }
      }
    }
  }
}

int main(void) {
  int n_layout = 1;
  reset();
  init();
  while (true) {
    n_sol = 0;
    for (int i = 0; i < 7; i++)  
      for (int j = 0; j < 8; j++) 
        if (scanf("%d", &G[i][j]) != 1) return 0;
        
    if (n_layout > 1) {
      printf("\n\n\n\n\n");
    }
    printf("Layout #%d:\n\n\n", n_layout);
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        printf("  %2d", G[i][j]);
      }
      printf("\n");
    }
    printf("\n");
    printf("Maps resulting from layout #%d are:\n\n\n", n_layout);
    solve(0,0);
    printf("There are %d solution(s) for layout #%d.\n",
           n_sol, n_layout++); 
  }  
  return 0;
}
