// 965
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isUnivalTree(TreeNode* root) {
  if (root == NULL) return true;
  bool leftEq = true, rightEq = true;
  if (root -> left != NULL) leftEq = root -> val == root -> left -> val;
  if (root -> right != NULL) rightEq = root -> val == root -> right -> val;
  return leftEq && rightEq && isUnivalTree(root -> left) && isUnivalTree(root -> right);
}