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
    // https://oj.leetcode.com/problems/binary-tree-postorder-traversal/
    /*
    // Recursive
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }
    
    void postorderHelper(TreeNode *root, vector<int> &result) {
        if (root == NULL) return;
        postorderHelper(root->left, result);
        postorderHelper(root->right, result);
        result.push_back(root->val);
    }
    */
    
    // Iteratively
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *p = root;
        stack<TreeNode*> st;
        
        while (p != NULL) {
            st.push(p);
            if (p->left != NULL) {
                p = p->left;
            }
            else if (p->right != NULL) {
                p = p->right;
            }
            else {
                st.pop();  // p == st.top()
                result.push_back(p->val);
                while (!st.empty()) {
                    if (st.top()->right == p || st.top()->right == NULL) {
                        // it's time to visit st.top()
                        p = st.top();
                        st.pop();
                        result.push_back(p->val);
                    }
                    else {
                        p = st.top()->right;
                        break;
                    }
                }
                
                if (st.empty()) break;
            }
        }
        
        return result;
    }
};