#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
  int title_to_number(string column_title) {
    const int base = 26;
    int res = 0;
    for (int i = column_title.length()-1, j = 0; j < column_title.length(); i--, j++)
      res += (column_title[i] - 64) * pow(base, j);
    return res;
  }
};

int main() {
  string col_title = "ZY";
  Solution sol;
  int col = sol.title_to_number(col_title);
  cout << "Column Title: " << col_title << " -> " << col << endl;
  return 0;
}
