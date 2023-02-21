#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  unordered_set<int> s;
  bool is_happy(int n) {
    int x = n;
    int sq = 0;
    while (x) {
      const int r = x % 10;
      sq += r*r;
      x /= 10;
    }
    if (sq == 1) return true;
    if (s.find(sq) == s.end()) {
      s.insert(n);
      return is_happy(sq);
    } else return false;
  }
};

int main() {
  int n = 1;
  Solution sol;
  bool happy = sol.is_happy(n);
  cout << "Happy Number (" << happy << "): " << happy << endl;
  return 0;
}
