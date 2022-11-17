#include <iostream>

using namespace std;

class Solution {
public:
  bool has_path_sum(TreeNode *root, int target_sum) {
    if (root == NULL) return false;
    if (target_sum == root->val && root->left == nullptr && root->right == nullptr) return true;
    if (has_path_sum(root->left, target_sum - root->val) || has_path_sum(root->right, target_sum - root->val))
      return true;
    return false;
  }
};

int main() {
  Solution sol;
  int hps = sol.has_path_sum(root, 5);
  cout << hps << endl;
}
