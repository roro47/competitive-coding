// Accepted
#include <iostream>
#include <queue>
#include <set>
#include <climits>
using namespace std;

struct Node {
  int state[3];
  int dist; // amount of water poured
  Node(): dist(0) {}
  Node(int a_, int b_, int c_, int dist_): dist(dist_) {
    state[0] = a_;
    state[1] = b_;
    state[2] = c_;
  }
  bool operator==(const struct Node &node) const  {
    return state[0] == node.state[0]
        && state[1] == node.state[1]
        && state[2] == node.state[2];
  }
  bool operator<(const struct Node &node) const {
    return dist > node.dist;
  }
};

int a, b, c, d, min_d, min_dist;
int capacity[3];
int visit[200][200];

void reset() {
  min_d = INT_MAX;
  min_dist = INT_MAX;
  for (int i = 0; i < 200; i++) {
    for (int j = 0; j < 200; j++) {
      visit[i][j] = 0;
    }
  }
}

/* return new from and to state, and the change in volume*/
pair<pair<int, int>, int> pour(int f_curr, int f_max,
                               int to_curr, int to_max) {
  pair<pair<int, int>, int> p;

  /*
  cout << "from curr: " << f_curr << " from_max: " << f_max << endl;
  cout << "to curr: " << to_curr << " to_max: " << to_max << endl;
  */
  p.second = (to_max - to_curr) > f_curr ?
             f_curr : (to_max - to_curr);
  p.first.first = f_curr - p.second;
  p.first.second = to_curr + p.second;
  /*
  cout << "After: " << endl;
  cout << "       from: " << p.first.first << endl;
  cout << "       to  : " << p.first.second << endl;
  cout << "       change : " << p.second << endl;
  */
  return p;
}

void solve() {
  priority_queue<struct Node> q;
  q.push(Node(0, 0, capacity[2], 0));

  visit[0][0] = 1;
  while (!q.empty()) {
    struct Node node = q.top(); q.pop();

    // check if the target is valid
    for (int i = 0; i < 3; i++) {
      if (node.state[i] <= d) {
        if (min_d > (d - node.state[i])) {
          min_dist = node.dist;
          min_d = d - node.state[i];
        } else if (min_d == (d - node.state[i])) {
          min_dist = node.dist > min_dist ? min_dist : node.dist;
        }
      }
      if (node.state[i] == d) {
        min_d = 0;
        return;
      }
    }
    
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i != j)  {
          /* pour from i to j */
          struct Node next = node;
          pair<pair<int, int>, int> p =
              pour(node.state[i], capacity[i],
                   node.state[j], capacity[j]);
          next.state[i] = p.first.first;
          next.state[j] = p.first.second;
          next.dist += p.second;
          if (!visit[next.state[0]][next.state[1]]) {
            //states.insert(next);
            visit[next.state[0]][next.state[1]] = 1;
            q.push(next);
          }
        }
      }
    }
  }
}

int main(void) {
  int n_case;
  scanf("%d", &n_case);
  while (n_case--) {
    reset();
    scanf("%d%d%d%d", &capacity[0], &capacity[1], &capacity[2], &d);
    solve();
    printf("%d %d\n", min_dist, d - min_d);
  }
  return 0;
}
