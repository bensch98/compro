#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int remove_element(vector<int> &nums, int val) {
    int n = nums.size();
    int i = -1;
    int flag = 0;
    for (int j = 0; j < n; j++) {
      if (nums[j] != val) {
        flag = 1;
        i++;
        nums[i] = nums[j];
      }
    }
    if (flag) return i + 1;
    return 0;
  }
};

int main() {
  // testcase
  vector<int> v = { 0, 1, 2, 2, 3, 0, 4, 2 };
  int val = 2;

  // print vector before modifying
  for (auto &i : v)
    cout << i << ", ";
  cout << endl;

  // run solution
  Solution sol;
  int removed = sol.remove_element(v, val);

  // print vector after modifying
  for (auto &i : v)
    cout << i << ", ";
  cout << endl;
  cout << "First " << removed << " elements are correct" << endl;

  return 0;
}
