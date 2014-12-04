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
    bool symHelper(TreeNode *t1, TreeNode *t2) {
        if (t1 == NULL) return t2 == NULL;
        if (t2 == NULL || t1->val != t2->val) return false;
        
        return symHelper(t1->left, t2->right) && symHelper(t1->right, t2->left);
    }

public:
    bool isSymmetric(TreeNode *root) {
        /* https://oj.leetcode.com/problems/symmetric-tree/
        */
        
        // Recursively
        if (root == NULL) return true;
        return symHelper(root->left, root->right);
        
    }
};