#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool contains_duplicate(vector<int> &nums) {
    unordered_set<int> uset;
    for (const auto &i : nums) {
      if (uset.find(i) == uset.end())
        uset.insert(i);
      else return true;
    }
    return !(nums.size() == uset.size());
  }
};

int main() {
  vector<int> nums = {1, 1, 2, 3 };
  Solution sol;
  bool dups = sol.contains_duplicate(nums);
  cout << "Duplicates: " << (dups ? "true" : "false") << endl;
  return 0;
}
