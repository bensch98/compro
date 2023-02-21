#include <iostream>

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
  int min_depth(TreeNode *root) {
    if (root == NULL) return 0;
    int ld = min_depth(root->left);
    int rd = mind_depth(root->right);
    if (root->left == nullptr && root->right == nullptr)
      return 1;
    if (root->left == nullptr)
      return 1 + rd;
    if (root->right == nullptr)
      return 1 + ld;
    return 1 + min(ld, rd);
  }
};

int main() {
  TreeNode *root = new TreeNode();
  Solution sol;
  int d = sol.min_depth(root)
  return 0;
}
