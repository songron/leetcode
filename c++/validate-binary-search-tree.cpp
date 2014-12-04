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
    bool bstHelper(TreeNode *root, int minValue, int maxValue) {
        if (root == NULL) return true;
        if (root->val <= minValue || root->val >= maxValue) return false;
        
        return bstHelper(root->left, minValue, root->val) && bstHelper(root->right, root->val, maxValue);
    }
    
public:
    bool isValidBST(TreeNode *root) {
        /* https://oj.leetcode.com/problems/validate-binary-search-tree/
        Top-down is simpler !
        */
        
        return bstHelper(root, INT_MIN, INT_MAX);
    }
};