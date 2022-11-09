#include <iostream>

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
  bool is_same_tree(TreeNode *p, TreeNode *q) {
    if (p != NULL && q != NULL) {
      if (p->val != q->val) return false;
      if (is_same_tree(p->left, q->left) && is_same_tree(p->right, q->right))
        return true;
    } else if (p == NULL && q == NULL) {
      return true;
    }
    return false;
  }
};

int main() {
  //create testcase
  TreeNode p, q;

  // run solution
  Solution sol;
  sol.is_same_tree(&p, &q);

  return 0;
}
