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
    ListNode *deleteDuplicates(ListNode *head) {
        /* https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
        */
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *t = head;
        while (t->next != NULL) {
            if (t->next->val == t->val) {
                ListNode *tmp = t->next->next;
                delete t->next;
                t->next = tmp;
            }
            else {
                t = t->next;
            }
        }
        
        return head;
    }
};