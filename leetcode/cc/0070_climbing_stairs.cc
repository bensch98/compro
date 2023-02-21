#include <iostream>

using namespace std;

class Solution {
public:
  int climb_stairs(int n) {
    if (n++ == 0) return 0;
    int i = 0;
    int j = 1;
    int k;
    while (n--) {
      k = j;
      if (!n) return k;
      j += i;
      i = k;
    }
    return k;
  }

  int climb_stairs_rec(int n) {
    if (n == 0) return 0; 
    if (n == 1) return 1;
    if (n == 2) return 2;
    return climb_stairs_rec(n-1) + climb_stairs_rec(n-2);
  }
};

int main() {
  // testcase
  int stairs = 45;

  // solution
  Solution sol;
  int res = sol.climb_stairs(stairs);
  cout << res << " steps" << endl;

  return 0;
}
