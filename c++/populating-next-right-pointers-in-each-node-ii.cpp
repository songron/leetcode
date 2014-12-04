/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
        if (root == NULL) return;
        
        TreeLinkNode *cur = root;
        TreeLinkNode *dummy = new TreeLinkNode(0);
        
        while (cur != NULL) {
            // every level is like a linked list
            TreeLinkNode *tail = dummy;
            while (cur != NULL) {
                if (cur->left != NULL) {
                    tail->next = cur->left;
                    tail = tail->next;
                }
                if (cur->right != NULL) {
                    tail->next = cur->right;
                    tail = tail->next;
                }
                cur = cur->next;
            }
            cur = dummy->next;
            dummy->next = NULL;
        }
        
        delete dummy;
    }
};