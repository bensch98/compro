#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int length_of_last_word(string s) {
    int len = s.length() - 1;
    if (len == -1) return 0;  
    int i = max(0, len);

    while (s[i] == ' ' && i >= 0) i--;
    int j = i;

    while (i >= 0) {
      if (s[i] == ' ')
        return j - i;
      i--;
    }
    return j - i;
  }
};

int main() {
  // testcase
  string s = "  fly me    to   the moon  ";

  Solution sol;
  int len = sol.length_of_last_word(s);
  cout << "Length of last word: " << len << endl;

  return 0;
}
