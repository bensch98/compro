#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plus_one_1(vector<int> &digits) {
    if (digits.size() == 0) return digits;
    
    for (vector<int>::reverse_iterator rit = digits.rbegin(); rit != digits.rend(); ++rit) {
      if (*rit < 9) {
        (*rit)++;
        return digits;
      }
      *rit = 0;
    }

    if (digits[0] == 0)
      digits.insert(digits.begin(), 1);

    return digits;
  }

  vector<int> plus_one(vector<int> &digits) {
    if (digits.size() == 0) return digits;
    int carry_over = 1;
    for (vector<int>::reverse_iterator rit = digits.rbegin(); rit != digits.rend(); ++rit) {
      if (carry_over) {
        carry_over = ((*rit+1) % 10 < *rit) % 10 ? 1 : 0;
        (*rit)++;
        *rit %= 10;
      } else return digits;
    }

    if (digits[0] == 0)
      digits.insert(digits.begin(), 1);

    return digits;
  }

};

int main() {
  // testcase
  vector<int> digits = { 8, 9, 9, 9 };

  Solution sol;
  sol.plus_one(digits);

  for (auto &i : digits)
    cout << i << ", ";
  cout << endl;

  return 0;
}
