#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
using namespace std;
const int maxn = 6 + 10;
struct Node {
  struct Node left;
  struct Node right;
  int val;
  Node(): left(nullptr), right(nullptr), val(0) {}
  Node(struct Node l, struct Node r):
      left(l), right(r), val(l.val + r.val) {}
  Node(int v) : left((-1)), right(Node(-1)), val(v) {}
};
vector<struct Node> nodes;
double r;
int s;
double max_width = 0;
map<vector<struct Node>, int> visit;

void reset() {
  visit.clear();
  max_width = 0;
  nodes.clear();
}

pair<double, double> calculate_(struct Node node) {
  pair<double, double> lp, rp;
  double wl, wr;
  if (node.left.val == -1 && node.right.val == -1) {
    lp = calculate_(node.left);
    wl = node.left.val;
    rp = calculate_(node.right);
    wr = node.right.val;
    if (lp.first == -1 || rp.first == -1) {
      return lp;
    }
    double left_width, right_width;
    left_width = wr / (wl + wr);
    right_width = 1 - left_width;
    double total_left, total_right;
    total_left = left_width + lp.first;
    total_right = right_width + rp.second;
    // special condition
    if (lp.second > 1 + rp.second) {
      total_right = lp.second - left_width;
    }
    if (rp.first > 1 + lp.first) {
      total_left = rp.first - right_width;
    }
    return pair<double, double>(total_left, total_right);
  } else if (node.left.val == -1 && node.right.val == -1) {
    return pair<double, double>(0, 0);
  } else {
    return pair<double, double>(-1, -1);
  }
}

double calculate(struct Node node) {
  pair<double, double> p = calculate_(node);
  return p.first + p.second;
}

void print_node(struct Node node) {
  if (node.left != nullptr) {
    print_node(*(node.left));
  }
  if (node.left == nullptr && node.right == nullptr) {
    cout << node.val << " ";
  }
  if (node.right != nullptr) {
    print_node(*(node.right));
  }
}
  
void solve(vector<struct Node> nodes) {
  if (nodes.size() == 1) {
    double width = calculate(nodes[0]);
    if (width > max_width && width < r && width > 0) {
      max_width = width;
    }
    return;
  }
  for (int i = 0; i < nodes.size(); i++) {
    for (int j = i + 1; j < nodes.size(); j++) {
      //vector<struct Node> next_nodes = nodes;
      struct Node v1 = nodes[i], v2 = nodes[j];
      vector<struct Node> next_nodes;
      for (int k = 0; k < nodes.size(); k++) {
        if (k != i && k != j) {
          next_nodes.push_back(nodes[k]);
        }
      }
      //next_nodes.erase(next_nodes.begin()+i);
      //assert(find(next_nodes.begin(), next_nodes.end(), v2) != next_nodes.end());
      //next_nodes.erase(find(next_nodes.begin(), next_nodes.end(), v2));
      //next_nodes.push_back(Node(&v1, &v2));
      struct Node v3 = Node(v1, v2);
      struct Node v4 = Node(v2, v1);
      vector<struct Node> next_nodes2 = next_nodes;
      next_nodes.insert(next_nodes.begin(), v3);
      next_nodes2.insert(next_nodes2.begin(), v4);
      solve(next_nodes);
      solve(next_nodes2);
    }
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf("%lf", &r);
    reset();
    scanf("%d", &s);
    for (int i = 0; i < s; i++) {
      int d;
      scanf("%d", &d);
      nodes.push_back(Node(d));
    }
    solve(nodes);
    if (max_width == 0) {
      printf("%d\n", -1);
    } else {
      printf("%0.17f\n", max_width);
    }
  }
  return 0;
}
