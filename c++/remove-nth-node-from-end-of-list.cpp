//https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL) return NULL;
        
        ListNode *p = head;
        for (int i = 1; i < n && p != NULL; i++) {
            p = p->next;
        }
        if (p == NULL) return head;
        if (p->next == NULL) {
            p = head->next;
            delete head;
            return p;
        }
        
        ListNode *prev = head;
        p = p->next;
        while (p->next != NULL) {
            p = p->next;
            prev = prev->next;
        }
        p = prev->next;
        prev->next = p->next;
        delete p;
        
        return head;
    }
};