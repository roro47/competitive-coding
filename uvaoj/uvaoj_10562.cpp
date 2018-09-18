// Not Accepted
#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 200 + 10;

char buf[maxn][maxn];
int n;

bool is_node(char c) {
  return c != ' ' && c != '#' && c != '-' && c != '|' && !isspace(c);
}

void dfs(int l, int p) {
  cout << buf[l][p] << "(";
  int r = l + 2, c = l + 3;
  if (buf[l+1][p] == '|') { /* has leaf */
    int i = p;
    while (buf[r][i-1] == '-') i--;
    while (buf[r][i] == '-') {
      if (is_node(buf[c][i])) { dfs(c, i); }
      i++;
    }
  }
  cout << ")";
}
        
void solve() {
  n = 0;
  for (;;) {
    fgets(buf[n], maxn, stdin);
    if (buf[n][0] == '#') break; else n++;
  }

  cout << "(";
  if (n) {
    for (int i = 0; i < strlen(buf[0]); i++) {
      if (is_node(buf[0][i])) {
        dfs(0, i);
        break;
      }
    }
  }
  cout << ")\n";
}

  

int main() {
  int t;
  scanf("%d", &t); getchar();

  while (t--) {
    for (int i = 0; i < maxn; i++) {
      for (int j = 0; j < maxn; j++) {
        buf[i][j] = ' ';
      }
    }
    solve();
  }

  return 0;
}

/*
vector<pair<char, char>> tree;

struct Node {
  char val;
  vector<struct Node> children;
  Node(char v): val(v) {}
};

char root;
bool is_node(char chr) {
  return chr != ' ' && chr != '|'  && chr != '#' && chr != '-';
}
void parse(vector<struct Node> &parent_nodes, string parent, string range, string child) {
  int start = -1, end = -1;
  char p;
  vector<char> childs;
  int len = max(max(range.size(), parent.size()), child.size());
  for (int i = 0; i < len; i++) {
    if (range[i] == '-') {
      if (is_node(parent[i]) && i < parent.size()) p = parent[i];
      if (is_node(child[i]) && i < child.size()) childs.push_back(child[i]);
      if (start == -1) {
        start = i;
      }
    } else {
      if (is_node(parent[i])) {
        tree.push_back(pair<char, char>(parent[i], '#'));
      }
      if (start != -1) {
        
        for (auto c : childs) {
          p_node.children.push_back(pair<char, char>(p, c));
        }
        childs.clear();
        start = -1;
      }
    }   
  }
  if (!childs.empty()) {
    for (char c : childs) {
      tree.push_back(pair<char, char>(p, c));
    }
  }
}

void print_tree(char root, int start) {
  cout << root << "(";
  for (int i = start; i < tree.size(); i++) {
    if (tree[i].first == root) {
      if (tree[i].second == '#') {
        tree[i].first = '#';
        break;
      }
      print_tree(tree[i].second, i);
      
    }
  }
  cout << ")";
}
   
int main(void) {
  int n;
  scanf("%d", &n); getchar();
  string parent, range, child;
  while (n-- && getline(cin, parent)) {
    tree.clear();
    root = ' ';
    for (int i = 0; i < parent.size(); i++) {
      if (is_node(parent[i])) {
        root = parent[i]; break;
      }
    }
    
    while (true && root != ' ') {
      getline(cin, range);
      if (range[0] == '#') break;
      getline(cin, range);
      getline(cin, child);
      parse(parent, range, child);
      parent = child;
    }
    if (root == ' ') {
      cout << "()" << endl;
    } else {
      cout << "("; print_tree(root, 0); cout << ")" << endl;
    }
  }
  return 0;
}
*/
