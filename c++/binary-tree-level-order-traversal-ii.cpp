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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		// https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
        vector<vector<int> > result;
        if (root == NULL) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            result.push_back(vector<int>());
            for (int i = 0; i < count; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp->left != NULL) q.push(tmp->left);
                if (tmp->right != NULL) q.push(tmp->right);
                result.back().push_back(tmp->val);
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};