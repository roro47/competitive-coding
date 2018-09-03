// Not Accepted
#include <iostream>
#include <map>
#include <string>
#include <cassert>
using namespace std;

#define DECLARE 1
#define ASSIGN  2

// globals
bool bug;
map<string, int> array_size;
map<string, int> array_index;
vector<vector<int>> arrays_storage;

struct array_ {
  string name;
  string index_str;
};

int type(string line) {
  for (int i = 0; i < line.size(); i++) {
    if (line[i] == '=') return ASSIGN;
  }
  return DECLARE;
}

bool is_array(string s) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '[') return true;
  }
  return false;
}

// can only operate on assign statement
string left(string line) {
  for (int i = 0; i < line.size(); i++) {
    if (line[i] == '=') {
      return line.substr(0, i);
    }
  }
  assert(false);
  return string();
}

// apply only to form of this -> a[10]
struct array_ parse(string line) {
  struct array_ a;

  for (int i = 0; i < line.size(); i++) {
    if (line[i] == '[') {
      a.name = line.substr(start, i);
      break;
    }
  }

  a.index_str = line.substr(a.name.size());
  return a;
}

int eval(string index_str) {
  if (!is_array(index_str)) {
    return stoi(index_str);
  }

  struct array_ a = parse(index_str);

  if (array_index.count(a.name)) { // array doesn't exist
    bug = true;
    return -1;
  }

  int index = eval(a.index_str);
  if (index == -1 || 
      index >= array_size[a.name] ||  // index out of range
      array_storage[array_index[a.name]] == -1 || // not assigned
      bug) {
    bug = true;
    return -1;
  }
  return array_storage[array_index[a.name]][index];
}

int main(void) {
  string line = "*";
  
  int num_line = 0;
  int num_array = 0;

  while (getline(cin, line)) {
    while (line[0] != '.') {
      
      if (bug) continue;

      if (type(line) == DECLARE) {

        struct array_ a = parse(line);
        array_size[a.name] = eval(a.index_str);
        array_index[a.name] = num_array++;

      } else { // type is ASSIGN

        string left_op = left(line);
        string right_op = line.substr(left_op.size());
        struct array_ left_a = parse(left_op);
        int val = eval(right_op);
        if (bug) {
          break;
        }
        array_storage[array_index[left_a.name]] = val;

      }
      num_line++;
    }
    // finished a program
    if (bug) {
    }
    getline(cin, line);
  }
  return 0;
} 
