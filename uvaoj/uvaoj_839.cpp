// Accepted
#include <iostream>
#include <cstdio>
using namespace std;

const int num_max_nodes = 100000;

bool balance = true;

int input() {
  int wl, dl, wr, dr;
  scanf("%d%d%d%d", &wl, &dl, &wr, &dr);
  int left, right;

  if (wl == 0) {
    left = input();
  } else {
    left = wl;
  }

  if (wr == 0) {
    right = input();
  } else {
    right = wr;
  }
  balance = balance && (dl * left == dr * right);
  return left + right;
}


int main(void) {
  int n;
  string filter;
  scanf("%d", &n);
  while (n--) {
    getline(cin, filter);
    input();
    if (balance) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    balance = true;
    if (n != 0) {
      cout << endl;
    }
  }
  return 0;
}
