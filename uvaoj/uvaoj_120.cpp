// Accepted
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;
void reverse(vector<int>::iterator begin, vector<int>::iterator end) {
  while (end - begin >= 0) {
    int tmp = *begin;
    *begin = *end;
    *end = tmp;
    begin++; end--;
  }
}
int main() {
  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    int d;
    vector<int> stack;
    while (ss >> d) {
      stack.push_back(d);
    }
    if (!stack.size()) break;
    for (int i = 0; i < stack.size(); i++) {
      printf("%d", stack[i]);
      if (i != stack.size() -1) {
        printf(" ");
      }
    }
    printf("\n");
    vector<int> sorted = stack;
    sort(sorted.begin(), sorted.end());
    for (int i = sorted.size() - 1; i >= 0;) {
      auto iter = find(stack.begin(), stack.end(), sorted[i]);
      if (iter - stack.begin() == i) {
        i--;
        continue;
      }
      if (iter != stack.begin()) {
        printf("%d ", stack.size() - (iter - stack.begin()));
        reverse(stack.begin(), iter);
        if (i == 0) continue;
      }
      printf("%d ", sorted.size() - i);
      reverse(stack.begin(), stack.begin() + i);
    }
    printf("0\n");
  }
  return 0;
}
