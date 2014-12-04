//https://oj.leetcode.com/problems/partition-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *left = new ListNode(-1), *right = new ListNode(-1);
        ListNode *leftTail = left, *rightTail = right;
        
        while (head != NULL) {
            if (head->val < x) {
                leftTail->next = head;
                leftTail = head;
            }
            else {
                rightTail->next = head;
                rightTail = head;
            }
            head = head->next;
        }
        
        leftTail->next = right->next;
        rightTail->next = NULL;
        head = left->next;
        delete left;
        delete right;
        
        return head;
    }
};