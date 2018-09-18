#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
using namespace std;

int dy[4] = { 0, 1, -1, 0 };
int dx[4] = { 1, 0, 0, -1 };
char chr[4] = { 'e', 'n', 's', 'w'};
map<char, char> m;
const int maxn = 335;
const int BLOCK = 3;
const int VISITED = 1;
const int UNVISITED = 0;

int G[maxn][maxn];
int n_sol = 0;

void reset() {
  memset(G, '\0', maxn*maxn*sizeof(char));
}

void write(int y, int x, int val) {
  int x_ = x + 160 , y_ = y + 160;
  G[y_][x_] = val;
}

int read(int y, int x) {
  int x_ = x + 160, y_ = y + 160;
  return G[y_][x_];
}

int len, n_block;

bool valid(int r, int c, int dir, int size) {
  for (int i = 1; i <= size-1; i++) {
    int x_ = c + dx[dir]*i;
    int y_ = r + dy[dir]*i;
    if (x_ == 0 && y_ == 0) {
      return false;
    }
    if (read(r, c) == BLOCK || read(y_, x_) == BLOCK) {
      return false;
    }
    /*
    if (read(y_, x_) == VISITED) {
      return false;
    }
    */
    
  }
  return true;
}


void solve(int y, int x, int prev, vector<int> path) {
  if (read(y, x) == BLOCK) return;
  if (x == 0 && y == 0 && prev != -1 && path.size() != len) {
    return;
  }
  if (path.size() == len) {
    if (x == 0 && y == 0) {
      for (auto dir: path) {
        printf("%c", chr[dir]);
      }
      printf("\n"); n_sol++;
    }
    return;
  }    

  if (read(y, x) == VISITED) return;
  for (int i = 0; i < 4; i++) {
    if ((prev == -1 || m[chr[i]] != chr[prev]) &&
        valid(y, x, i, path.size() + 1) &&
        prev != i) {
      vector<int> path_ = path;
      path_.push_back(i);
      
      for (int k = 0 ; k < path_.size(); k++) {
        int x_ = x + dx[i] * k;
        int y_ = y + dy[i] * k;
        write(y_, x_, VISITED);
      }
        
      int x_ = x + dx[i]*path_.size(), y_ = y + dy[i]*path_.size();
      solve(y_, x_, i, path_);
      
      for (int k = 0 ; k < path_.size(); k++) {
        int x_ = x + dx[i] * k;
        int y_ = y + dy[i] * k;
        write(y_, x_, UNVISITED);
      }
    }
  }
}

  
int main(void) {
  int n_city;
  m['e'] = 'w'; m['w'] = 'e';
  m['n'] = 's'; m['s'] = 'n';
  
  scanf("%d", &n_city);
  for (int k = 0; k < n_city; k++) {
    reset();
    n_sol = 0;
    if (k) printf("\n");
    scanf("%d%d", &len, &n_block);
    for (int i = 0; i < n_block; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      write(y,x,BLOCK);
    }
    solve(0, 0, -1, vector<int>());
    printf("Found %d golygon(s).\n", n_sol);
  }
  return 0;
}
