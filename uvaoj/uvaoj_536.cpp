// Accepted
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 26 + 10;
char preorder[maxn];
char inorder[maxn];

void solve(int pre_l, int pre_r, int in_l, int in_r) {
  char root = preorder[pre_l];
  if (root == '\0') return;
  if (pre_l < pre_r - 1 && in_l < in_r - 1) {
    int n_left = find(inorder + in_l, inorder + in_r, root) - inorder - in_l;
    int n_right = in_r - 1 - in_l - n_left;
    if (n_left != 0) {
      solve(pre_l + 1, pre_l + 1 + n_left, in_l, in_l + n_left);
    }
    if (n_right != 0) {
      solve(pre_l + 1 + n_left, pre_r, in_l + n_left + 1, in_r);
    }
  }
  cout << root;
}

int main(void) {
  while (scanf("%s%s", preorder, inorder) == 2) {
    solve(0, strlen(preorder), 0, strlen(inorder));
    cout << endl;
  }
  return 0;
}
