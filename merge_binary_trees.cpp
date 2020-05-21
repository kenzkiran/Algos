/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *root = nullptr;
  void MergeValues(TreeNode *t1, TreeNode *t2, TreeNode **out) {
    if (t1 == nullptr && t2 == nullptr) {
      return;
    }

    if (t1 != nullptr || t2 != nullptr) {
      *out = new TreeNode();
      TreeNode *t1_next_left = nullptr;
      TreeNode *t2_next_left = nullptr;
      TreeNode *t1_next_right = nullptr;
      TreeNode *t2_next_right = nullptr;

      if (t1 != nullptr) {
        t1_next_left = t1->left;
        t1_next_right = t1->right;
        (*out)->val = t1->val;
      }
      if (t2 != nullptr) {
        t2_next_left = t2->left;
        t2_next_right = t2->right;
        (*out)->val += t2->val;
      }
      MergeValues(t1_next_left, t2_next_left, &(*out)->left);
      MergeValues(t1_next_right, t2_next_right, &(*out)->right);
    }
  }

  TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
    MergeValues(t1, t2, &root);
    return root;
  }
};

int main() {
  return 0;
}