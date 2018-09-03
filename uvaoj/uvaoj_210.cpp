// Accepted
#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

map<char, int> table;

struct program {
  deque<string> prog;
  int id;
}; 

deque<struct program> bq; /* block queue */
deque<struct program> pq; /* program queue */

int num_p, t1, t2, t3, t4, t5, q, locked;
const int ASSIGN = 1;
const int OUTPUT = 2;
const int BME    = 3;
const int EME    = 4;
const int STOP   = 5;

int type(string &line) {
  if (line == "end") return STOP;
  if (line == "unlock") return EME;
  if (line == "lock") return BME;
  if (line.size() > 5 && line.substr(0, 5) == "print") return OUTPUT;
  return ASSIGN;
}

int stored = 0;

struct program execute(struct program p) {
  int q_ = q;
  while (q_ > 0 && !p.prog.empty()) {
    string inst = p.prog.front();
    switch (type(inst)) {
      case ASSIGN:
        table[inst[0]] = stoi(inst.substr(4));
        q_ -= t1;
        break;
      case OUTPUT:
        cout << p.id << ": " << table[inst[6]] << endl;
        q_ -= t2;
        break;
      case BME:
        if (locked) {
          stored = 1;
          bq.push_back(p);
          return p;
        }
        locked = 1;
        q_ -= t3;
        break;
      case EME:
        locked = 0;
        if (!bq.empty()) {
          pq.push_front(bq.front());
          bq.pop_front();
        }
        q_ -= t4;
        break;
      case STOP:
        q_ -= t5;
        break;
    }
    p.prog.pop_front();
  }
  return p;
}
int num_case;

int main(void) {
  scanf("%d", &num_case);
  while (num_case--) {
    bq.clear();
    pq.clear();
    table.clear();
    cin >> num_p >> t1 >> t2 >> t3 >> t4 >> t5 >> q;
    locked = 0;
    int id = 1;
    string line;
    getline(cin, line); 
    while (num_p--) {
      struct program p;
      while (getline(cin, line) && line != "end") {
        p.prog.push_back(line);
      }
      p.prog.push_back(line);
      p.id = id++;
      pq.push_back(p);
    }

    while (!pq.empty()) {
      struct program p = pq.front();
      pq.pop_front();
      p = execute(p);
      if (stored) {
        stored = 0;
        continue;
      }
      if (!p.prog.empty()) {
        pq.push_back(p);
      }
    }
    if (num_case > 0) {
      cout << endl;
    }
  }
  return 0;
}
