#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> two_sum(vector<int> &nums, int target) {
    // O(n)
    unordered_map<int, int> num2idx;
    int search;
    for (int i = 0; i < nums.size(); i++) {
      search = target - nums[i];
      if (num2idx.find(search) != num2idx.end() && num2idx.at(search) != i)
        return vector<int>{i, num2idx.at(search)};
      num2idx[nums[i]] = i;
    }
    return vector<int>{-1, -1};
  }

  vector<int> two_sum_0(vector<int> &nums, int target) {
    // O(n*log(n))
    for (size_t i = 0; i < nums.size(); i++) {
      for (size_t j = 0; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          return vector<int>{static_cast<int>(i), static_cast<int>(j)};
        }
      }
    }
    return vector<int>{-1, -1};
  }
};

int main() {
  // create testcase
  vector<int> vec = { 2, 7, 11, 15 };
  int target = 9;

  // run solution
  Solution sol;
  vector<int> res = sol.two_sum(vec, target);

  // print result
  cout << "Index 0: " << res[0] << ", Index 1: " << res[1] << endl;

  return 0;
}
