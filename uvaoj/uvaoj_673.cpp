#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 128 + 10;
char A[maxn];

int test(int cur) {
  if (A[cur] == '(' || A[cur] == '[') {
    int idx = test(cur + 1);
    if (idx == -1) return idx;
    if ((A[idx] == ')' && A[cur] == '(') ||
        (A[idx] == ']' && A[cur] == '[')) {
      return test(idx + 1);
    } else {
      return -1;
    }
  }
  if (A[cur] == ')' || A[cur] == ']') {
    return cur;
  }
  if (A[cur] == '\0') {
    return cur;
  }
  return -1;
}

int test_() {
  int i = 0;
  while (i != -1 && A[i] != '\0') {
    int j = test(i);
    if (j == i) return false;
    i = j;
  }
  return i != -1;
}

int main(void) {
  int n;
  scanf("%d", &n); getchar();
  while (n--) {
    memset(A, '\0', maxn);
    fgets(A, maxn, stdin);
    A[strlen(A) - 1] = '\0'; 
    //cout << "A :" << A << "<" << endl;
    if (test_()) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
  
  
