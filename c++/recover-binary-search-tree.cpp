//https://oj.leetcode.com/problems/recover-binary-search-tree/

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
    void recoverTree(TreeNode *root) {
        assert(root != NULL);
        
        TreeNode *first = NULL, *second = NULL;
        TreeNode *last = NULL;
        
        helper(root, first, second, last);
        assert(first != NULL);
        if (second == NULL) second = last;
        swap(first->val, second->val);
    }
    
    void helper(TreeNode *root, TreeNode *&first, TreeNode *&second, TreeNode *&last) {
        if (root == NULL) return;
        if (first != NULL && second != NULL) return;
        
        helper(root->left, first, second, last);
        
        if (last == NULL) {
            last = root;
            helper(root->right, first, second, last);
            return;
        }
        
        if (first == NULL && root->val < last->val) {
            first = last;
        }
        else if (first != NULL && root->val > first->val) {
            second = last;
            return;
        }
        
        last = root;
        helper(root->right, first, second, last);
    }
};