// Accepted
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
using namespace std;

map<string, string> users;
/*
void store(string &s) {
  str_id[s] = num_str++;
  str_ref.push_back(s);
}
*/

pair<string, string> parse(string user) {
  pair<string, string> p;
  for (int i = 0; i < user.size(); i++) {
    if (user[i] == '@') {
      p.first = user.substr(0, i);
      break;
    }
  }
  p.second = user.substr(p.first.size() + 1);
  return p;
}

int main(void) {
  string s, city, user;
  int n;
  
  while (cin >> s) {
    if (s[0] == '*') {
      break;
    }
    if (s == "MTA") {
      cin >> city;
      cin >> n;
      while (n--) {
        cin >> user;
        users[user] = city;
      }
    }
  }

  string sender, receiver, message;
  string filter;
  string pad(5, ' ');
  while (cin >> sender) {
    if (sender[0] == '*') {
      break;
    }
    pair<string, string> sender_p = parse(sender);
    
    vector<pair<string, string>> receivers;
    while (cin >> receiver) {
      if (receiver[0] == '*') {
        break;
      }
      if (find(receivers.begin(), receivers.end(), parse(receiver)) 
          == receivers.end()) {
        receivers.push_back(parse(receiver));
      }
    }
    message = string();
    string part;
    getline(cin, part);
    while (true) {
      getline(cin, part);
      if (part[0] == '*') {
        break;
      }
      message += pad;
      message += part;
      message += '\n';
    }
    
    city = " ";
    while (!receivers.empty()) {
      pair<string, string> rp = *receivers.begin();
      city = rp.second;
      bool sent_data = false;

      cout << "Connection between " << sender_p.second
           << " and " << city << endl;
      cout << pad << "HELO " << sender_p.second << endl;
      cout << pad << "250" << endl;
      cout << pad << "MAIL FROM:<" << sender_p.first << "@"
           << sender_p.second << ">" << endl;
      cout << pad << "250" << endl;

      for (auto begin = receivers.begin(); begin != receivers.end();) {
        if (city != begin->second) {
          begin++;
          continue;
        }
        cout << pad << "RCPT TO:<" << begin->first << "@" 
             << begin->second << ">" << endl;
        if (city != users[begin->first]) { // users don't exist
          cout << pad << "550" << endl;
        } else {
          sent_data = true;
          cout << pad << "250" << endl;
        }
        begin = receivers.erase(begin);
      }
      
      if (sent_data) {
        cout << pad << "DATA" << endl;
        cout << pad << "354" << endl;
        cout << message;
        cout << pad << "." << endl;
        cout << pad << "250" << endl;
      }
      cout << pad << "QUIT" << endl;
      cout << pad << "221" << endl;
    }
  }
  return 0;
}
  
