#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int cur = m + n - 1;
    while (cur >= 0)
      if (nums2[j] > nums1[i])
        nums1[cur--] = nums2[j--];
      else
        nums1[cur--] = nums1[i--];
  }
};

int main() {
  // testcase
  vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
  int m = 3;
  vector<int> nums2 = { 2, 5, 6 };
  int n = 3;

  // solution
  Solution sol;
  sol.merge(nums1, m, nums2, n);

  // print result
  for (auto it : nums1)
    cout << it << ", ";
  cout << endl;

  return 0;
}
