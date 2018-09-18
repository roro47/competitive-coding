// Accepted (pointer link list)
// Accepted (array)
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;


// Array implementation
const int num_max_node = 266;
const int root = 1;
int left_[num_max_node];
int right_[num_max_node];
int have_value[num_max_node];
int val[num_max_node];
int cnt;
bool complete;

void reset() {
  for (int i = 0; i <= num_max_node; i++) {
    left_[i] = 0;
    right_[i] = 0;
    have_value[i] = 0;
    val[i] = 0;
  }
  complete = true;
  cnt = 1;
}

int newnode() {
  return ++cnt;
}

void addnode(int v, char *path) {
  int curr = root;
  while (*path != ')') {
    if (*path == 'L') {
      if (!left_[curr]) {
        left_[curr] = newnode();
      }
      curr = left_[curr];
    } else if (*path == 'R') {
      if (!right_[curr]) {
        right_[curr] = newnode();
      }
      curr = right_[curr];
    }
    path++;
  }
  if (have_value[curr]) {
    complete = false;
  }
  have_value[curr] = 1;
  val[curr] = v;
}


void print_tree() {
  vector<int> nodes;
  queue<int> q;
  q.push(root);
  while (!q.empty() && complete) {
    int n = q.front();
    q.pop();
    if (!have_value[n]) {
      complete = false;
      break;
    }
    nodes.push_back(val[n]);
    if (left_[n]) q.push(left_[n]);
    if (right_[n]) q.push(right_[n]);
  }
  if (!complete) {
    cout << "not complete" << endl;
  } else {
    for (int i = 0; i < nodes.size(); i++) {
      cout << nodes[i];
      if (i != nodes.size() - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }
}


int main(void) {
  char node[100];
  reset();
  while (scanf("%s", node) == 1) {
    if (!strcmp(node, "()")) {
      print_tree();
      reset();
      continue;
    }
    int v = strtol(node + 1, NULL, 10);
    if (*(strchr(node, ',') + 1) == ')') {
      have_value[root] = 1;
      val[root] = v;
    } else {
      addnode(v, strchr(node, ','));
    }
  }
  return 0;
}
// tree implemented with struct

/*
struct Node {
  bool has_value;
  struct Node *left, *right;
  int val;
  Node() : has_value(false), left(NULL), right(NULL), val(0) {};
};

Node *root;
int n; // number of nodes
bool complete;

Node *new_node() {
  return new Node();
}

void addnode(int v, char *path) {
  Node *curr = root;
  while (*path != ')') {
    if (*path == 'L') {
      if (curr->left == NULL) {
        curr->left = new_node();
      }
      curr = curr->left;
    } else {
      if (curr->right == NULL) {
        curr->right = new_node();
      }
      curr = curr->right;
    }
    path++;
  }
  curr->has_value = true;
  curr->val = v;
}

void print_tree() {
  vector<int> nodes;
  queue<Node *> q;
  q.push(root);
  while (!q.empty() && complete) {
    Node *node = q.front();
    q.pop();
    if (node->has_value) nodes.push_back(node->val);
    if (node->left) q.push(node->left);
    if (node->right) q.push(node->right);
  }

  if (!complete || nodes.size() < n) {
    cout << "not complete" << endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    cout << nodes[i];
    if (i != n - 1) {
      cout << " ";
    }
  }
  cout << endl;
}

void delete_tree(Node *node) {
  if (node != NULL) {
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
  }
}
  
int main(void) {
  char node[100];
  root = new_node();
  complete = true;
  n = 1;
  while (scanf("%s", node) == 1) {
    if (!strcmp(node, "()")) {
      print_tree();
      delete_tree(root);
      root = new_node();
      complete = true;
      n = 1;
      continue;
    }
    int val = strtol(node + 1, NULL, 10);
    if (*(strchr(node, ',') + 1) == ')') {
      root->has_value = true;
      root->val = val;
    } else {
      addnode(val, strchr(node, ','));
      n++;
    }
  }
  delete_tree(root);
  return 0;
}
*/
