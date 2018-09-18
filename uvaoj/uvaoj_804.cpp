#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100 + 10;
struct transition {
  int input[maxn];
  int output[maxn];
  int count[maxn]; 
  int n_input, n_output;
  transition() : n_input(0), n_output(0) {
    for (int i = 0; i < maxn; i++) {
      count[i] = 0;
    }
  }
};

int places[maxn];
vector<struct transition> transitions; 
int np = maxn, nt = maxn, n_case = 1;

void reset() {
  transitions.clear();
  for (int i = 0; i <= np; i++) {
    places[i] = 0;
  }
}
  
void op(int n_op) {
  bool operate = true;
  int k;
  for (k = n_op; k && operate; k--) {
    operate = false;
    for (int i = 0; i < transitions.size(); i++) {
      struct transition &t = transitions[i];
      bool enabled = true;
      for (int j = 0; j < t.n_input && enabled; j++) {
        enabled &= (places[t.input[j]] &&
                    places[t.input[j]] >= t.count[t.input[j]]);
      }
      if (enabled) {
        for (int j = 0; j < t.n_input; j++) 
          places[t.input[j]] = places[t.input[j]] ?
                               places[t.input[j]] - 1 : 0;
        for (int j = 0; j < t.n_output; j++) 
          places[t.output[j]] += 1;
        operate = true;
        break;
      }
    }
  }
  printf("Case %d: ", n_case++);
  if (operate) {
    printf("still live after %d transitions\n", n_op);
  } else {
    printf("dead after %d transitions\n", n_op - k - 1);
  }
  int total = 0;
  printf("Places with tokens:"); 
  for (int i = 1; i <= np; i++) {
    if (places[i]) {
      printf(" %d (%d)", i, places[i]);
    }
  }
  printf("\n\n");
}

int main(void) {
  while (scanf("%d", &np) == 1 && np) {
    reset();
    for (int i = 1; i <= np; i++) {
      scanf("%d", &places[i]);
    }
    scanf("%d", &nt);
    while (nt--) {
      int p;
      struct transition t;
      while (scanf("%d", &p) && p) {
        if (p < 0) {
          t.input[t.n_input++] = -p;
          t.count[-p]++;
        }
        else {
          t.output[t.n_output++] = p;
          t.count[p]++;
        }
      }
      transitions.push_back(t);
    }
    int n_op;
    scanf("%d", &n_op);
    op(n_op);
  }
  return 0;
}
