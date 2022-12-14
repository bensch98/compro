#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool contains_nearby_duplicate(vector<int> &nums, int k) {
    unordered_set<int> us;
    if (k <= 0) return false;
    for (int i = 0; i < nums.size(); i++) {
      if (i > k) us.erase(nums[i-k-1]);
      if (us.find(nums[i]) != us.end()) return true;
      us.insert(nums[i]);
    }
    return false;
  }
};

int main() {
  vector<int> nums = { 1, 2, 3, 1, 2, 3 };
  int k = 3;

  Solution sol;
  bool nearby_dup = sol.contains_nearby_duplicate(nums, k);
  cout << "Nearby duplicate: " << (nearby_dup ? "true" : "false") << endl;

  return 0;
}
