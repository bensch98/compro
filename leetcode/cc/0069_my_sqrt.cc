#include <iostream>

using namespace std;

class Solution {
public:
  int my_sqrt(int x) {
    long i = x;
    while (i * i > x) i = (i + x / i) / 2;
    return (int)i;
  }

  int my_sqrt_2(int x) {
    long i = 0;
    while (i * i <= x) i++;
    return (int) i - 1;
  }
};

int main() {
  // testcase
  int x = 16;

  // solution
  Solution sol;
  int y = sol.my_sqrt(x);
  cout << y << endl;

  return 0;
}
