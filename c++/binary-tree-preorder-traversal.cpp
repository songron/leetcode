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
	//https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
    /*
    // Recursive
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }
    
    void preorderHelper(TreeNode *root, vector<int> &result) {
        if (root == NULL) return;
        result.push_back(root->val);
        preorderHelper(root->left, result);
        preorderHelper(root->right, result);
    }
    */
    
    // Iteratively
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *p = root;
        stack<TreeNode*> st;
        
        while (p != NULL) {
            result.push_back(p->val);
            if (p->right != NULL) {
                st.push(p->right);
            }
            if (p->left != NULL) {
                p = p->left;
            }
            else if (!st.empty()) {
                p = st.top();
                st.pop();
            }
            else {
                break;
            }
        }
        
        return result;
    }
};