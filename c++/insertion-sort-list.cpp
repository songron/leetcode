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
    ListNode *insertionSortList(ListNode *head) {
        /* https://oj.leetcode.com/problems/insertion-sort-list/
        Using insertion sort
        */
        
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        while (head->next != NULL) {
            ListNode *p = dummy;
            while (p != head && p->next->val <= head->next->val) {
                p = p->next;
            }
            if (p == head) {
                head = head->next;
                continue;
            }
            
            ListNode *tmp = head->next->next;
            head->next->next = p->next;
            p->next = head->next;
            head->next = tmp;
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }
};