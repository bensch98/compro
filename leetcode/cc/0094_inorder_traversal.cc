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
  vector<int> inorder_traversal(TreeNode* root) {
    vector<int> res = {};
    vector<int> tmp;
    if (root != NULL) {
      res = inorder_traversal(root->left);
      res.push_back(root->val);
      tmp = inorder_traversal(root->right);
      res.insert(res.end(), tmp.begin(), tmp.end());
    }
    return res;
  }
}

int main() {
  // create testcase
  TreeNode root;

  // run solution
  Solution sol;
  sol.inorder_traversal(&root)

  return 0;
}
