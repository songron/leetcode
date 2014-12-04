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
    bool hasPathSum(TreeNode *root, int sum) {
        /* https://oj.leetcode.com/problems/path-sum/
        The path must be root-to-leaf.
        */
        
        stack<TreeNode*> st;
        int curSum = 0;
        
        while (root != NULL) {
            curSum += root->val;
            st.push(root);
            if (root->left) {
                root = root->left;
            }
            else if (root->right) {
                root = root->right;
            }
            else {
                if (curSum == sum) return true;
                curSum -= root->val;
                st.pop();
                
                while (!st.empty()) {
                    if (st.top()->right == NULL || st.top()->right == root) {
                        root = st.top();
                        st.pop();
                        curSum -= root->val;
                    }
                    else {
                        root = st.top()->right;
                        break;
                    }
                }
                
                if (st.empty()) break;
                
            }
        }
        
        return false;
    }
};