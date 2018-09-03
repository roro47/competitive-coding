// Accepted
#include <iostream>
using namespace std;

const int MAX = 100002;
int left_[MAX];
int right_[MAX];
int m,n;
void link(int x, int y) {
  right_[x] = y; left_[y] = x;
}

void print_b() {
  int b = right_[0];
  for (int i = 1; i <= n; i++) {
    cout << b << " ";
    b = right_[b];
  }
  cout << endl;
}

int main(void) {
  int kcase = 1;
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 1; i <= n; i++) {
      left_[i] = i - 1;
      right_[i] = i + 1;
    }
    right_[0] = 1; left_[n+1] = n;
    //print_b();
    int inv = 0;
    while (m--) {
      int op, x, y, lx, rx, ly, ry;
      scanf("%d", &op);
      if (op == 4) {
        inv  = !inv; continue;
      } else {
        scanf("%d%d", &x, &y);
        lx = left_[x]; rx = right_[x]; ly = left_[y]; ry = right_[y];
        op = op != 3 && inv ? 3 - op : op;
        if (op == 1 && x == ly) continue;
        else if (op == 2 && x == ry) continue;
        /*
        cout << "x: " << x << " "
             << "y: " << y << " "
             << "lx: " << left_[x] << " "
             << "rx: " << right_[x] << " "
             << "ly: " << left_[y] << " "
             << "ry: " << right_[y]
             << endl;
             */
        if (op == 1) {
          link(lx, rx); link(ly, x); link(x, y);
        } else if (op == 2) {
          link(lx, rx); link(y, x); link(x, ry);
        } else if (op == 3) {
          if (rx == y) {
            link(lx, y);
            link(y, x);
            link(x, ry);
          } else if (y == lx) {
            link(ly, x);
            link(x, y);
            link(y, rx);
          } else {
            link(ly, x); link(x, ry);
            link(lx, y); link(y, rx);
          }
        }
        //print_b();
        /*
        cout << "x: " << x << " "
             << "y: " << y << " "
             << "lx: " << left_[x] << " "
             << "rx: " << right_[x] << " "
             << "ly: " << left_[y] << " "
             << "ry: " << right_[y]
             << endl;
             */
      }
    }
    int b = 0;
    long long ans  = 0;
    for (int i = 1 ; i <= n; i++) {
      b = right_[b];
      if (i % 2 == 1) ans += b;
    }
    if (inv && n % 2 == 0) {
      ans = (long long) n*(n+1) / 2 - ans;
    }

    cout << "Case " << kcase++ << ": " << ans << endl;
  }
  return 0;
}

      

        
