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
    void flatten(TreeNode *root) {
        /* https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
        * preorder traversal
        */
        
        stack<TreeNode*> st;
        TreeNode *p = root;
        TreeNode *dummy = new TreeNode(0), *tail = dummy;
        
        while (p != NULL) {
            tail->left = NULL;
            tail->right = p;
            tail = p;
            
            if (p->right) {
                st.push(p->right);
            }
            if (p->left) {
                p = p->left;
            }
            else {
                if (st.empty()) break;
                p = st.top();
                st.pop();
            }
        }
        
        delete dummy;
    }
};