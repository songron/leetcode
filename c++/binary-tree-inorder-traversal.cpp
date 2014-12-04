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
    // https://oj.leetcode.com/problems/binary-tree-inorder-traversal/
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *p = root;
        stack<TreeNode*> st;
        
        while (p != NULL) {
            st.push(p);
            if (p->left != NULL) {
                p = p->left;
            }
            else {
                do {
                    p = st.top();
                    st.pop();
                    result.push_back(p->val);
                    if (p->right != NULL) {
                        p = p->right;
                    }
                    else {
                        p = NULL;
                    }
                } while (!st.empty() && p == NULL);
            }
        }
        
        return result;
    }

};