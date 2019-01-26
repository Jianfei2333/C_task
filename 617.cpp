// 617
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
  if (t1 == NULL && t2 == NULL) return NULL;
  else if (t1 == NULL) {
    TreeNode* new_tree = new TreeNode(t2 -> val);
    new_tree -> left = mergeTrees(NULL, t2 -> left);
    new_tree -> right = mergeTrees(NULL, t2 -> right);
    return new_tree;
  }
  else if (t2 == NULL) {
    TreeNode* new_tree = new TreeNode(t1 -> val);
    new_tree -> left = mergeTrees(t1 -> left, NULL);
    new_tree -> right = mergeTrees(t1 -> right, NULL);
    return new_tree;
  } else {
    TreeNode* new_tree = new TreeNode(t1 -> val + t2 -> val);
    new_tree -> left = mergeTrees(t1 -> left, t2 -> left);
    new_tree -> right = mergeTrees(t1 -> right, t2 -> right);
    return new_tree;
  }
}