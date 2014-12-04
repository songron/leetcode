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
    int helper(TreeNode *root, int &result) {
        if (root == NULL) return 0;
        
        int left = helper(root->left, result);
        int right = helper(root->right, result);
        int cur = root->val + left + right;
        if (cur > result) result = cur;
        
        if (left + root->val > 0 || right + root->val > 0) {
            return max(left, right) + root->val;
        }
        return 0;
    }

public:
    int maxPathSum(TreeNode *root) {
        /* https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
        The path may start and end at any node.
        Every node can be the "pivot"!
        */
        
        if (root == NULL) return 0;
        
        int result = INT_MIN;
        helper(root, result);
        
        return result;
    }
};