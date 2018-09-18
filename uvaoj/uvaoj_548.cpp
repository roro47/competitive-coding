// Accepted -shorter
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <climits>
#include <utility>
using namespace std;

const int num_max_nodes = 10010;
int in_order[num_max_nodes];
int post_order[num_max_nodes];

int root = 0;
int left_[num_max_nodes];
int right_[num_max_nodes];

int num_nodes = -1;

void reset() {
  for (int i = 0; i < num_max_nodes; i++) {
    left_[i] = 0;
    right_[i] = 0;
    in_order[i] = 0;
    post_order[i] = 0;
  }
  num_nodes = 0;
  root = 0;
}

int buildtree(int in_start, int in_end,
               int post_start, int post_end) {
  if (in_start >= in_end - 1) {
    return in_order[in_start];
  }
  int curr_root = post_order[post_end-1];
  /* find the position of curr_root in given inorder range */
  int in_root_idx = find(in_order + in_start, in_order + in_end, curr_root) -
                    in_order;
  int num_left_nodes = in_root_idx - in_start;
  int num_right_nodes = in_end - (in_root_idx + 1);
  if (num_left_nodes != 0) {
    left_[curr_root] = buildtree(in_start, in_start + num_left_nodes,
        post_start, post_start + num_left_nodes);
  }
  if (num_right_nodes != 0) {
    right_[curr_root] = buildtree(in_start + num_left_nodes + 1, in_end,
        post_start + num_left_nodes, post_end - 1);
  }
  return curr_root;
}

pair<long long int, int> find_min_leaf(int node, pair<long long int, int> p) {
  int leaf = p.second;
  if (!left_[node] && !right_[node]) {
    return pair<long long int, int>(node, node);
  }
  
  long long int min_sum = LLONG_MAX;
  int min_leaf;
  if (left_[node]) {
    pair<long long int, int> lp = 
      find_min_leaf(left_[node], pair<long long int, int>(left_[node], INT_MAX));
    min_sum = lp.first;
    min_leaf = lp.second;
  }

  if (right_[node]) {
    pair<long long int, int> rp = 
      find_min_leaf(right_[node], pair<long long int, int>(right_[node], INT_MAX));
    if (min_sum == rp.first) {
      min_leaf = min_leaf < rp.second ? min_leaf : rp.second;
    } else if (min_sum > rp.first) {
      min_sum = rp.first;
      min_leaf = rp.second;
    }
  }
  return pair<long long int, int>(min_sum + node, min_leaf); 
}
 
int main(void) {
  char chr;
  int cnt;
  string inorder, postorder;
  while (getline(cin, inorder) && getline(cin, postorder)) {
    reset();
    stringstream ss(inorder); cnt = 0;
    while (ss >> in_order[cnt++]);
    ss = stringstream(postorder); cnt = 0;
    while (ss >> post_order[cnt++]);
    num_nodes = cnt - 1;
    root = buildtree(0, num_nodes, 0, num_nodes);
    cout << find_min_leaf(root, pair<long long int, int>(LLONG_MAX, INT_MAX)).second << endl;
  }
  return 0;
}
