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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // https://oj.leetcode.com/problems/merge-two-sorted-lists/
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        
        l1 = dummy->next;
        delete dummy;
        return l1;
    }
};