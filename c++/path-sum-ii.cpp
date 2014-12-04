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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        /* https://oj.leetcode.com/problems/path-sum-ii/
        */
        
        vector<vector<int> > result;
        
        stack<TreeNode*> st;
        vector<int> answer;
        int curSum = 0;
        
        while (root != NULL) {
            answer.push_back(root->val);
            curSum += root->val;
            st.push(root);
            
            if (root->left) {
                root = root->left;
            }
            else if (root->right) {
                root = root->right;
            }
            else {
                if (curSum == sum) result.push_back(answer);
                answer.pop_back();
                curSum -= root->val;
                st.pop();
                
                while (!st.empty()) {
                    if (st.top()->right == NULL || st.top()->right == root) {
                        root = st.top();
                        st.pop();
                        answer.pop_back();
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
        
        return result;
    }
};