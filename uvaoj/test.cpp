#include <deque>
#include <vector>
#include <iostream>
using namespace std;
int main(void) {
  deque<int> d;
  d.push_back(1);
  vector<int> v;
  v.push_back(2);
  v.push_back(3);
  d.insert(d.end(), v.begin(), v.end());
  for (auto c: d) {
    cout << c << " ";
  }
  cout << endl;
  return 0;
}
