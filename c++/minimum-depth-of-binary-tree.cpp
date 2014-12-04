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
    int minDepth(TreeNode *root) {
        /* https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
        The end node of a path must be a leaf node.
        */
        
        if (root == NULL) {
            return 0;
        }
        
        /* 
        // Recursively
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }

        int leftDep = root->left == NULL ? INT_MAX : minDepth(root->left);
        int rightDep = root->right == NULL ? INT_MAX : minDepth(root->right);
        return min(leftDep, rightDep) + 1;
        */
        
        // Iteratively
        stack<TreeNode*> st;
        TreeNode *p = root;
        int depth = 0, result = INT_MAX;
        
        while (p != NULL) {
            ++depth;
            st.push(p);
            if (p->left) {
                p = p->left;
            }
            else if (p->right) {
                p = p->right;
            }
            else { // a leaf node
                if (depth < result) result = depth;
                --depth;
                st.pop();
                
                while (!st.empty()) {
                    if (st.top()->right == NULL || st.top()->right == p) {
                        --depth;
                        p = st.top();
                        st.pop();
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