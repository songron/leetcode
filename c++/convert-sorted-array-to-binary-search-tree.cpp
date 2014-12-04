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
private:
    TreeNode *convertHelper(vector<int> &num, int start, int end) {
		// https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
        if (start > end) return NULL;
        
        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = convertHelper(num, start, mid-1);
        root->right = convertHelper(num, mid+1, end);
        
        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return convertHelper(num, 0, num.size()-1);
    }
};