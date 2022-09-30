#include <iostream>
#include <bitset>
#include <string>

using namespace std;

class Solution {
public:
  string add_binary(string a, string b) {
    int i = a.length();
    int j = b.length();
    int co = 0; // carry over
    char c1, c2;
    c1 = c2 = '0';
    string c = "";

    while (max(i--, j--)) {
      c1 = i >= 0 ? a[i] : '0';
      c2 = j >= 0 ? b[j] : '0';

      if (c1 == '1' ^ c2 == '1') {
        if (co)
          c.insert(0, 1, '0');
        else {
          c.insert(0, 1, '1');
        }
      } else if (c1 == '1' && c2 == '1') {
        if (co)
          c.insert(0, 1, '1');
        else {
          c.insert(0, 1, '0');
          co = 1;
        }
      } else if (c1 == '0' && c2 == '0') {
        if (co) {
          c.insert(0, 1, '1');
          co = 0;
        } else
          c.insert(0, 1, '0');
      }
    }

    if (co) c.insert(0, 1, '1');

    return c;
  }
};

int main () {
  // testcase
  string a = "10";
  string b = "100";

  // solution
  Solution sol;
  string c = sol.add_binary(a, b);
  cout << "Result: " << c << endl;

  return 0;
}
