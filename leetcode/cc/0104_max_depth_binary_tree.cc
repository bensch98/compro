#include <iostream>

struct TreeNode {
  int val;
  int *left;
  int *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  int max_depth(TreeNode *root) {
    if (root == NULL) return 0;
    int ld = max_depth(root->left);
    int rd = max_depth(root->right);
    return max(ld, rd) + 1; 
  }

  int max_depth_2(TreeNode *root) {
    return count_max_depth(TreeNode root, 0);
  }

  int count_max_depth(treenode *p, int depth) {
    int ld, rd;
    if (p != NULL) {
      depth++;
      ld = count_max_depth(p->left, depth);
      rd = count_max_depth(p->right, depth);
      return ld > rd ? ld : rd;
    }
    return depth;
  }
};

int main() {
  TreeNode root;
  Solution sol;
  sol.max_depth(&root);
  return 0;
}
