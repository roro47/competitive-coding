// Accepted
#include <iostream>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

const int num_max_piles = 100000;
int piles[num_max_piles];
int curr;
int start;

void reset() {
  for (int i = 0; i < num_max_piles; i++) {
    piles[i] = 0;
  }
  curr = 5000;
  start = 5000;
}
/*
void pile(stringstream &ss) {
  int root;
  ss >> root;
  if (root == -1) {
    return;
  }
  cout << "root :" << root << endl;
  int left_, right_;
  ss >> left_;
  cout << "left : " << left_<< endl;
  if (left_ != -1) {
    pile(ss);
  } 
  piles[curr++] += root;
  ss >> right_;
  cout << "right: " << right_ << endl;
  if (right_ != -1) {
    pile(ss);
  }
}
*/
int pile() {
  int root;
  scanf("%d", &root);
  if (root == -1) {
    return -1;
  }
  piles[curr] += root; 
  curr--; 
  if (pile() != -1) {
    start = start < curr ? start : curr;
  }
  curr++;
  
  curr++; pile(); curr--;
  
  return 0;
}

int main(void) {
  for (int i = 0; i < num_max_piles; i++) {
    piles[i] = 0;
  }
  curr = 0;
  string line;
  int kcase = 1;
  while (true) {
    reset();
    pile();
    if (piles[5000] == 0) {
      break;
    } else {
    }
    cout << "Case " << kcase++ << ":" << endl;
    for (int i = start; piles[i] != 0; i++) {
      cout << piles[i];
      if (piles[i+1] != 0) {
        cout << " ";
      }
    }
    cout << endl;
    cout << endl;
  }
  return 0;
}  
