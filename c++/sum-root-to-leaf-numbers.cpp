//https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/

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
public:
    int sumNumbers(TreeNode *root) {
        if (root == NULL) return 0;
        
        int result = 0;
        return sumHelper(root, 0);
    }
    
    int sumHelper(TreeNode *root, int sum) {
        if (root == NULL) return 0;
        
        sum = sum * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            return sum;
        }
        
        return sumHelper(root->left, sum) + sumHelper(root->right, sum);
    }
};