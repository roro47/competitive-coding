// Accepted
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <deque>
using namespace std;
const int max_name_len = 1000;
const int max_n = 10;
const int n_dir = 4;

struct Node {
  int r, c, dir;
  Node():r(-1), c(-1), dir(-1) {}
  Node(int n1, int n2, int n3): r(n1), c(n2), dir(n3) {}
};

int maz[max_n][max_n][n_dir][n_dir];
int d[max_n][max_n][n_dir];
struct Node p[max_n][max_n][n_dir];
int sr, sc, sd, gr, gc;

void reset() {
  for (int i = 0; i < max_n; i++) {
    for (int j = 0; j < max_n; j++) {
      for (int k = 0; k < n_dir; k++) {
        for (int m = 0; m < n_dir; m++) {
          maz[i][j][k][m] = 0;
        }
        d[i][j][k] = -1;
      }
    }
  }
}


int turn(int dir, char t) {
  switch (t) {
    case 'F':
      return dir;
    case 'L':
      return ((dir + 4) - 1) % 4;
    case 'R':
      return (dir + 1) % 4;
  }
  return dir;
}

int encode(char dir) {
  switch (dir) {
    case 'N':
      return 0;
    case 'E':
      return 1;
    case 'S':
      return 2;
    case 'W':
      return 3;
  }
  return 0;
}

/* walk in the updated direction */
void walk(struct Node &node) {
  int dr[4] = { -1, 0, 1, 0 };
  int dc[4] = { 0, 1,  0, -1 };
  node.r = node.r + dr[node.dir];
  node.c = node.c + dc[node.dir];
}
  

void print_ans(struct Node node) {
  deque<struct Node> nodes;
  for (;;) {
    nodes.push_front(node);
    if (d[node.r][node.c][node.dir] == 0) break;
    node = p[node.r][node.c][node.dir];
  }
  nodes.push_front(Node(sr, sc, sd));
   
  int cnt = 1;
  for (int i = 0; i < nodes.size(); i++) {
    if (i % 10 == 0) cout << " "; 
    printf(" (%d,%d)", nodes[i].r, nodes[i].c);
    if (i == nodes.size() -1 || cnt % 10 == 0) printf("\n");
    cnt++;
  }
}

void solve() {
  struct Node node = Node(sr, sc, sd);
  //cout << "before walk " << node.r << " " << node.c <<  " " << node.dir << endl;
  walk(node);
  //cout << "after walk " << node.r << " " << node.c <<  " " << node.dir << endl;
  queue<struct Node> nodes;
  nodes.push(node);
  d[node.r][node.c][node.dir] = 0;

  while (!nodes.empty()) {
    //cout << "size " << nodes.size() << endl;
    node = nodes.front();
    if (node.r == gr && node.c == gc) {
      print_ans(node);
      return;
    }
    nodes.pop();
      //cout << "curr-> r " << node.r << " c " << node.c << endl;
      for (int i = 0; i < 4; i++) {
        if (maz[node.r][node.c][node.dir][i] ) {
          //cout << "pushed " << endl;
          struct Node next = node;
          next.dir = i;
          walk(next);
          if (d[next.r][next.c][next.dir] < 0) {
            //cout << "curr-> r " << next.r << " c " << next.c << endl;
            d[next.r][next.c][next.dir] = d[node.r][node.c][node.dir] + 1;
            p[next.r][next.c][next.dir] = node;
            nodes.push(next);
            //cout << "pushed end" << endl;
          }
        }
    }
  }
  cout << "  No Solution Possible\n";
}


int main(void) {
  char name[max_name_len];
  while (fgets(name, max_name_len, stdin)) {
    if (!strcmp(name, "END\n")) break;
    reset();
    char sd_chr[2];
    scanf("%d%d%s%d%d", &sr, &sc, sd_chr, &gr, &gc);
    getchar();
    sd = encode(sd_chr[0]);
    char in[5];
    for (;;) {
      int r, c;
      scanf("%d", &r); if (r == 0) { getchar(); break; }
      scanf("%d", &c);
      //cout << "r " << r << " c " << c << endl;
      while (scanf("%s", in) == 1 && in[0] != '*') {
        int d = encode(in[0]);
        //cout << "in " << in << endl;
        for (int i = 1; i < strlen(in); i++) {
          maz[r][c][d][turn(encode(in[0]), in[i])] = 1;
        }
      }
      getchar();
    }
    cout << name;
    solve();
  }
  return 0;
}
