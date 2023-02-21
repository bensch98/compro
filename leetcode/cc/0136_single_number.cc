#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int single_number(vector<int> &nums) {
    int num = 0;
    for (auto x : nums)
      num ^= x;
    return num;
  }
};

int main() {
  vector<int> nums = { 4, 1, 2, 1, 2 };
  Solution sol;
  cout << "Single Number: " << sol.single_number(nums) << endl;
  return 0;
}
