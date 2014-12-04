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
    TreeNode *buildHelper(vector<int> &inorder, vector<int> &postorder, int istart, int pstart, int n) {
        if (n < 1) return NULL;
        
        TreeNode *root = new TreeNode(postorder[pstart+n-1]);
        int i = istart;
        for (; inorder[i] != root->val; i++) ;
        
        int n1 = i - istart, n2 = n - n1 - 1;
        root->left = buildHelper(inorder, postorder, istart, pstart, n1);
        root->right = buildHelper(inorder, postorder, i+1, pstart+n1, n2);
        
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        /* https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
        */
        
        return buildHelper(inorder, postorder, 0, 0, inorder.size());
    }
};