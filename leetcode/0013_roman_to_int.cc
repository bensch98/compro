#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

class Solution {
public:
  int roman_to_int(string s) {
    unordered_map<char, int> r2i;
    fill_r2i(r2i);
    int sum = 0;
    int last = 0;
    int cur = 0;
    int len = s.length();

    while (len--) {
      cur = r2i.at(s[len]);
      if (!sum || cur >= last) {
        // trivial case -> last character
        sum += cur;
      } else if (cur < last) {
        sum -= cur;
      }
      last = cur;
    }

    return sum;
  }

private:
  void fill_r2i(unordered_map<char, int> &r2i) {
    r2i['I'] = 1;  
    r2i['V'] = 5;
    r2i['X'] = 10;
    r2i['L'] = 50;
    r2i['C'] = 100;
    r2i['D'] = 500;
    r2i['M'] = 1000;
  }
};

int main() {
  // testcase
  vector<string> tests = { "III", "LVIII", "MCMXCIV" };

  // run solution
  Solution sol;
  int res = 0;
  for (vector<string>::iterator i = tests.begin(); i != tests.end(); i++) {
    res = sol.roman_to_int(*i);
    cout << *i << " = " << res << endl;
  }

  return 0;
}
