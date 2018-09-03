// Accepted
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

map<char, int> idx;
vector<vector<string>> dict;
vector<string> alpha;
map<string, int> processed;
map<string, int> words;

void process(string s) {
  if (processed.count(s)) {
    return;
  }
  
  if (s.size() > 1) {
    bool is_composed = false;
    bool is_compound = false;
    for (int k = 1; k < s.size(); k++) {
      string prestr = s.substr(0, k);
      string poststr = s.substr(k);

      if (words.count(prestr) && words.count(poststr)) {
        /*
        is_composed = true;
        process(prestr);
        process(poststr);
        if (processed[prestr] == 1 && processed[poststr] == 1) {
          if (!processed.count(s)) {
            processed[s] = 2;
          }
        } else {
          processed[s] = 3;
          return;
        }
        */
        processed[s] = 2;
        return;
      }
    }
    /*
    if (processed[s] == 2) {
      return;
    }
    */
  }
  processed[s] = 1;
}

int main(void) {
  string word;
  char chr = ' ';
  while (cin >> word) {
    words[word] = 1;
    if (chr != word[0] || chr == ' ') {
      if (chr != ' ') {
        dict.push_back(alpha);
      }
      idx[word[0]] = dict.size();
      chr = word[0];
      alpha.clear();
    }
    alpha.push_back(word);
  }
  dict.push_back(alpha);
  for (int i = 0; i < dict.size(); i++) {
    //cout << idx[dict[i][0][0]] << " " << dict[i][0][0]<< endl;
    for (int j = 0; j < dict[i].size(); j++) {
      process(dict[i][j]);
      if (processed[dict[i][j]] == 2) {
        cout << dict[i][j] << endl;
      }
    }
  }
  return 0;
}
