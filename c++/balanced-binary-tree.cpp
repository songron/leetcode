/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    // if balanced, return the depth
    // otherwise, return -1
    int getDepth(TreeNode *root) {
        if (root == NULL) return 0;
        int leftDep = getDepth(root->left), rightDep = getDepth(root->right);
        if (leftDep == -1 || rightDep == -1) {
            return -1;
        }
        if (leftDep >= rightDep) {
            return leftDep - rightDep <= 1 ? leftDep + 1 : -1;
        }
        return rightDep - leftDep <= 1 ? rightDep + 1 : -1;
    }

public:
    bool isBalanced(TreeNode *root) {
        return getDepth(root) != -1;
    }
};