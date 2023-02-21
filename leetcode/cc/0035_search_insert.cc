#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search_insert(vector<int> &nums, int target) {
    if (nums.size() == 0) return 0;
    int ub = nums.size();
    int lb = 0;
    int i = (lb + ub) / 2;
    int j = -1;
    while (1) {
      if (j == i) {
        if (nums[i] < target)
          return i + 1;
        else
          return i;
      }
      if (nums[i] == target)
        return i;
      else if (nums[i] > target)
        ub = i;
      else
        lb = i;
      j = i;
      i = (lb + ub) / 2;
    }
    return i;
  }
};

int main() {
  // testcase
  vector<int> v = { 1, 3, 5, 6 };
  int target = 5;

  // run solution
  Solution sol;
  int idx = sol.search_insert(v, target);
  cout << "Index: " << idx << endl;
  
  return 0;
}
