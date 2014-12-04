//https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL) return result;
        
        bool rev = false;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int count = q.size();
            vector<int> ans;
            for (int i = 0; i < count; i++) {
                TreeNode *tmp = q.front(); q.pop();
                ans.push_back(tmp->val);
                if (tmp->left != NULL) q.push(tmp->left);
                if (tmp->right != NULL) q.push(tmp->right);
            }
            
            if (rev) reverse(ans.begin(), ans.end());
            rev = !rev;
            result.push_back(ans);
        }
        
        return result;
    }
};