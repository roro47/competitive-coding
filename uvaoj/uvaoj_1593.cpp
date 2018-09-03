// Accepted
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(void) {

    string line, word;
    vector<vector<string>> words;
    vector<int> widths;
    int i = 0;
    int num_max_words = 0;

    /* collect and store the words */
    while (getline(cin, line)) {
        stringstream ss(line);
        words.push_back(vector<string>());
        while (ss >> word) {
            words[i].push_back(word);
        }
        num_max_words = num_max_words < words[i].size() ? 
            words[i].size() : num_max_words;
        i++;
    }

    /* measure the max length of words at each column */
    for (int j = 0; j < num_max_words; j++) {
        int max_len = 0;
        for (int k = 0; k < words.size(); k++) {
            if (j < words[k].size()) {
                max_len = max_len < words[k][j].size() ? words[k][j].size() : max_len;
            }
        }
        widths.push_back(max_len);
    }

    /* format print */
    for (int j = 0; j < words.size(); j++) {
        for (int k = 0; k < words[j].size(); k++) {
            string pad(widths[k] + 1 - words[j][k].size(), ' ');
            cout << words[j][k];
            if (k != words[j].size() - 1) {
                cout << pad;
            }
        }
        cout << endl;
    }
    return 0;
}
