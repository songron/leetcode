/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *buildHelper(ListNode *&head, int n) {
        if (n == 0) {
            return NULL; 
        }
        
        int half = n / 2;
        TreeNode *root = new TreeNode(0);
        root->left = buildHelper(head, half);
        root->val = head->val;
        head = head->next;
        root->right = buildHelper(head, n-1-half);
        return root;
    }

public:
    TreeNode *sortedListToBST(ListNode *head) {
        /* https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
        * Not as easy as "convert sorted array to binary search tree", because we cannot 
        * randomly access the element in a linked list by index.
        */
        
        int n = 0;
        for (ListNode *t = head; t != NULL; t = t->next) {
            n++;
        }
        
        return buildHelper(head, n);
    }
};