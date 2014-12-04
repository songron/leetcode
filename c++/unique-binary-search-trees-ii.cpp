//https://oj.leetcode.com/problems/unique-binary-search-trees-ii/

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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> result;
        helper(1, n, result);
        return result;
    }
    
    void helper(int start, int end, vector<TreeNode*> &result) {
        if (start > end) {
            result.push_back(NULL);
            return;
        }
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> tmpLeft, tmpRight;
            helper(start, i-1, tmpLeft);
            helper(i+1, end, tmpRight);
            
            for (int j = 0; j < tmpLeft.size(); j++) {
                for (int k = 0; k < tmpRight.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = tmpLeft[j];
                    root->right = tmpRight[k];
                    result.push_back(root);
                }
            }
        }
    }
};
