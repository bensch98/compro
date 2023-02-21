#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
  bool is_palindrome(int n) {
    if (n < 0) return false;
    int *m = new int(n);
    return is_pal_util(n, m);
  }
  
  bool is_palindrome_0(int x) {
    string s = to_string(x);
    string r = s;
    reverse_0(r);
    
    // alternatives:
    // ---
    // r = reverse_1(r);

    cout << "s: " << s << ", r: " << r << endl;
    return s == r;
  }

private:
  bool is_pal_util(int n, int *m) {
    // trivial case
    if (n >= 0 && n < 10) return true;
    if (!is_pal_util(n/10, m)) return false;
    *m /= 10;
    return (n % 10 == (*m) % 10);
  }

  void reverse_0(string &s) {
    reverse(s.begin(), s.end());
  }

  string reverse_1(string &s) {
    string r;
    int len = s.length();
    while (len--)
      r.push_back(s[len]);
    return r;
  }
};

int main() {
  // create testcases
  vector<int> tests = { 121, -121, 10 };

  // run solution
  Solution sol;

  for (vector<int>::iterator i = tests.begin(); i != tests.end(); i++) {
    bool res = sol.is_palindrome(*i);
    cout << *i << ": " << (res ? "yes" : "no") << endl;
  }

  return 0;
}
