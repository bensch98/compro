#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string longest_common_prefix(vector<string> &strs) {
    int j = 0;
    char c;
    int broke = 0;

    while (1) {
      if (j < strs[0].length())
        c = strs[0][j];
      for (vector<string>::iterator i = strs.begin(); i != strs.end(); i++) {
        if (j < (*i).length()) {
          if ((*i)[j] != c) {
            broke = 1;
            break;
          }
        } else {
          broke = 1;
          break;
        }
      }
      if (broke) break;
      j++;
    }

    return strs[0].substr(0, j);
  }
};

int main() {
  // testcase
  vector<vector<string>> strs = {
    { "flower", "flow", "flight"},
    { "dog", "racecar", "car"},
    { "" },
    { "a" }
  };

  // run solution
  Solution sol;
  for (vector<vector<string>>::iterator i = strs.begin(); i != strs.end(); i++) {
    cout << sol.longest_common_prefix(*i) << endl;
  }

  return 0;
}
