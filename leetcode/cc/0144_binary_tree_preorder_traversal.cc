#include <iostream>
#include <vector>
#include <stack>

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
  vector<int> preorder_traversal(TreeNode *root) {
    stack<TreeNode*> s;
    vector<int> v;
    while (1) {
      if (root) {
        s.push(root);
        v.push_back(root->val);
        root = root->left;
      } else {
        if (s.empty()) break;
        root = s.top();
        s.pop();
        root = root->right;
      }
    }
    return v;
  }

  vector<int> v;
  vector<int> preorder_traversal_1(TreeNode *root) {
    preorder(root);
    return v;
  }

  void preorder(TreeNode *root) {
    if (!root) return;
    v.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
  }
};

int main() {
  TreeNode *root = new TreeNode();
  Solution sol;
  vector<int> res = sol.preorder_traversal(root);
  return 0;
}
