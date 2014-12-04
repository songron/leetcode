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
    int maxDepth(TreeNode *root) {
        /* https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
        iteratively, postorder traversal
        */
        
        stack<TreeNode*> st;
        TreeNode *p = root;
        int depth = 0, result = 0;
        
        while (p != NULL) {
            depth++;
            st.push(p);
            if (p->left != NULL) {
                p = p->left;
            }
            else if (p->right != NULL) {
                p = p->right;
            }
            else { // p is a leaf node
                if (depth > result) result = depth;
                depth--;
                st.pop();
                
                while (!st.empty()) {
                    if (st.top()->right == p || st.top()->right == NULL) {
                        // it's time to visit st.top()
                        p = st.top();
                        depth--;
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