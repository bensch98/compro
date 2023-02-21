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
  bool is_balanced(TreeNode *root) {
    int lh, rh;
    if (root == NULL) return true;
    lh = btree_height(root->left);
    rh = btree_height(root->right);
    if (abs(lh - rh) <= 1 && is_balanced(root->left) && is_balanced(root->right))
      return true;
    return false;
  }

  int btree_height(TreeNode *tn) {
    if (tn == NULL)
      return 0;
    return 1 + max(btree_height(tn->left), btree_height(tn->right));
  }
};

int main() {
  TreeNode *root;
  Solution sol;
  sol.is_balanced(root);
  return 0;
}
