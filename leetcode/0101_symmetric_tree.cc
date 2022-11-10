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
  bool is_symmetric(TreeNode *root) {
    if (root == NULL) return true;
    return is_symmetric_rec(root->left, root->right);
  }

  bool is_symmetric_rec(TreeNode *p, TreeNode *q) {
    if (p == NULL && q == NULL) return true;
    else if (p == NULL || q == NULL) return false;
    else if (p->val != q->val) return false;
    return is_symmetric_rec(p->left, q->right) && is_symmetric_rec(p->right, q->left);
  }
};

int main() {
  TreeNode t;
  Solution sol;
  sol.is_symmetric(&t);
  return 0;
}
