#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
  bool is_valid(string s) {
    unordered_map<char, char> c2o = {
      { ')', '(' },
      { ']', '[' },
      { '}', '{' },
    };
    unordered_map<char, char> o2c = {
      { '(', ')' },
      { '[', ']' },
      { '{', '}' },
    };

    stack<char> stack;
    char tmp;
    for (int i = 0; i < s.length(); i++) {
      if (!contains_key(o2c, s[i]) && !contains_key(c2o, s[i])) continue;
      if (contains_key(o2c, s[i])) {
        stack.push(s[i]);
      } else if (!stack.empty()) {
        tmp = stack.top();
        stack.pop();
        if (tmp != c2o.at(s[i])) return false;
      } else {
        return false;
      }
    }

    if (stack.empty())
      return true;
    else
      return false;
  }

private:
  bool contains_key(unordered_map<char, char> &m, int k) { return m.find(k) != m.end(); }
};

int main() {
  // testcase
  vector<string> tests = {
    "()",
    "()[]{}",
    "(]",
    "([]){([])}",
  };

  Solution sol;
  for (vector<string>::iterator i = tests.begin(); i != tests.end(); i++) {
    cout << "Test case: " << *i << endl;
    cout << sol.is_valid(*i) << endl;
  }

  return 0;
}
