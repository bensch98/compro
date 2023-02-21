#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int majority_element(vector<int> &nums) {
    int cnt = 0;
    int cand = -1;
    for (auto num : nums) {
      if (cnt == 0)
        cand = num;
      if (num == cand)
        cnt++;
      else
        cnt--;
    }
    return cand;
  }

  int majority_element_1(vector<int> &nums) {
    unordered_map<int, int> counts;
    int half = nums.size() / 2;
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
      if (counts.find(*it) == counts.end())
        counts[*it] = 1;
      else
        counts[*it]++;
      if (counts[*it] > half)
        return *it;
      cout << *it << endl;
    }
    return 1;
  }
};

int main() {
  vector<int> nums = { 2, 2, 1, 1, 1, 2, 2 };
  Solution sol;
  int res = sol.majority_element(nums);
  cout << "Majority element: " << res << endl;
  return 0;
}
