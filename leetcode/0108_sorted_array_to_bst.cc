#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *sorted_array_to_bst(vector<int> &nums) {
    return sort_bst_rec(nums, 0, nums.size() - 1);  
  }

  TreeNode *sort_bst_rec(vector<int> &nums, int left, int right) {
    if (left > right) return NULL;
    int mid = (left + right) / 2;
    TreeNode *tn = new TreeNode(nums[mid]);
    tn->left = sort_bst_rec(nums, left, mid - 1);
    tn->right = sort_bst_rec(nums, mid + 1, right);
    return tn;
  }
};

int main() {
  vector<int> v = {-10, -3, 0, 5, 9};
  Solution sol;
  TreeNode *root = sol.sorted_array_to_bst(v);
  return 0;
}
