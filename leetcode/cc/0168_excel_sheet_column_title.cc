#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string convert_to_title(int column_number) {
    const int base = 26;
    string res = "";
    while(column_number > 0) {
      column_number -= 1;
      char c = (column_number % base) + 65;
      res += c;
      column_number /= base;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  int c = 701;
  Solution sol;
  string col = sol.convert_to_title(c);
  cout << c << " -> " << col << endl;
  return 0;
}
