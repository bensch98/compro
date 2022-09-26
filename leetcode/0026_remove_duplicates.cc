#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int remove_duplicates(vector<int> &nums) {
    // trivial cases
    if (nums.size() < 2) return nums.size();
    if (nums.size() == 2) {
      if (nums[0] == nums[1]) return 1;
      else return 2;
    }

    // modify vector
    int i = 0;
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[j] >= nums[i+1] && nums[j] != nums[i]) {
        i++;
        nums[i] = nums[j];
      }
    }
    return i + 1;
  }
};

int main() {
  // testcase
  vector<int> v = { -420, -69, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 69, 420, 420 };
  
  // run solution
  Solution sol;
  int removed = sol.remove_duplicates(v);
  cout << "First " << removed << " numbers are unique and ordered" << endl;

  // print vector
  for (auto &i : v)
    cout << i << ", ";
  cout << endl;

  return 0;
}
