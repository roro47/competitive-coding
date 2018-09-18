#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
using namespace std;

const int maxn = 6 + 10;
double max_width , r;
int s;

void reset() {
  max_width = 0;
}
int main(void) {
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf("%lf", &r);
    //printf("r : %lf\n", r);
    reset();
    scanf("%d", &s);
    for (int i = 0; i < s; i++) {
      int d;
      scanf("%d", &d);
      //stones.push_back(d);
      nodes.push_back(Node(d));
    }
    vector<struct Node*> nodes_ref;
    for (int i = 0; i < nodes.size(); i++) {
      nodes_ref.push_back(&nodes[i]);
    }
    solve(nodes_ref);
    if (max_width == 0) {
      printf("%d\n", -1);
    } else {
      printf("%0.17f\n", max_width);
    }
  }
  return 0;
}





/*
const int maxn = 6 + 10;
struct Node {
  struct Node *left, *right;
  int val;
  Node(): left(nullptr), right(nullptr), val(0) {}
  Node(struct Node *l, struct Node *r):
      left(l), right(r), val(l->val + r->val) {}
  Node(int v) : left(nullptr), right(nullptr), val(v) {}
  bool operator==(const struct Node &node) const {
    if (node.val == val) {
      bool equal = true;
      if (node.left == nullptr && left == nullptr) {
      } else if (node.left != nullptr && left != nullptr) {
        equal = equal && (*(node.left) == *left);
      } else {
        return false;
      }
      if (node.right == nullptr && right == nullptr) {
      } else if (node.right != nullptr && right != nullptr) {
        equal = equal && (*(node.right) == *right);
      } else {
        return false;
      }
      return equal;
    }
    return false;
  }
  bool operator<(const struct Node &node) const {
    return node.val < val;
  }
  //bool operator==(const struct Node &node) const {
    
};
//vector<int> stones;
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
  if (node.left != nullptr && node.right != nullptr) {
    lp = calculate_(*(node.left));
    wl = node.left->val;
    rp = calculate_(*(node.right));
    wr = node.right->val;
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
  } else if (node.left == nullptr && node.right == nullptr) {
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
  
void solve(vector<struct Node*> nodes_ref) {
  if (nodes_ref.size() == 1) {
    double width = calculate(nodes_ref[0]);
    if (width > max_width && width < r && width > 0) {
      max_width = width;
    }
    return;
  }
  for (int i = 0; i < nodes_ref.size(); i++) {
    for (int j = i + 1; j < nodes_ref.size(); j++) {
      struct Node *v1 = nodes_ref[i], *v2 = nodes_ref[j];
      vector<struct Node*> next_nodes_ref, next_nodes_ref2;
      for (int k = 0; k < nodes_ref.size(); k++) {
        if (k != i && k != j) {
          next_nodes_ref.push_back(nodes_ref[k]);
          next_nodes_ref2.push_back(nodes_ref[k]);
        }
      }
      nodes.push_back(Node(v1, v2));
      next_nodes_ref.insert(next_nodes_ref.begin(), &nodes[nodes.size()-1]);
      nodes.push_back(Node(v2, v1));
      next_nodes_ref2.insert(next_nodes_ref2.begin(), &nodes[nodes.size()-1]);
      solve(next_nodes_ref);
      solve(next_nodes_ref2);
    }
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf("%lf", &r);
    //printf("r : %lf\n", r);
    reset();
    scanf("%d", &s);
    for (int i = 0; i < s; i++) {
      int d;
      scanf("%d", &d);
      //stones.push_back(d);
      nodes.push_back(Node(d));
    }
    vector<struct Node*> nodes_ref;
    for (int i = 0; i < nodes.size(); i++) {
      nodes_ref.push_back(&nodes[i]);
    }
    solve(nodes_ref);
    if (max_width == 0) {
      printf("%d\n", -1);
    } else {
      printf("%0.17f\n", max_width);
    }
  }
  return 0;
}

*/
