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
    TreeNode *buildHelper(vector<int> &preorder, vector<int> &inorder, int pstart, int istart, int n) {
        if (n < 1) return NULL;
        
        TreeNode *root = new TreeNode(preorder[pstart]);
        int i = istart;
        for ( ; inorder[i] != preorder[pstart]; i++) ;
        
        int n1 = i - istart, n2 = n - n1 - 1;
        root->left = buildHelper(preorder, inorder, pstart+1, istart, n1);
        root->right = buildHelper(preorder, inorder, pstart+n1+1, i+1, n2);
        
        return root;
    }
    
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        /* https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
        * no duplicates
        */
        
        return buildHelper(preorder, inorder, 0, 0, preorder.size());
    }
};