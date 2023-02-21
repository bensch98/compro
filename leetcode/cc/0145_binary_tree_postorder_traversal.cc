#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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
  vector<int> postorder_traversal(TreeNode *root) {
    vector<int> v;
    if (!root) return v;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode *node = root;
    while (!s.empty()) {
      node = s.top();
      s.pop();
      if (node->left) s.push(node->left);
      if (node->right) s.push(node->right);
      v.push_back(node->val);
    }
    reverse(v.begin(), v.end());
    return v;
  }

  vector<int> v;
  vector<int> postorder_traversal_1(TreeNode *root) {
    postorder(root);
    return v;
  }

  void postorder(TreeNode *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    v.push_back(root->val);
  }
};

int main() {
  TreeNode *root = new TreeNode();
  Solution sol;
  vector<int> res = sol.postorder_traversal(root);
  return 0;
}
