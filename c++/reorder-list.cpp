/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *findMid(ListNode *head) {
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode *reverseList(ListNode *head) {
        ListNode *newHead = NULL;
        while (head) {
            ListNode *tmp = head->next;
            head->next = newHead;
            newHead = head;
            head = tmp;
        }
        return newHead;
    }

public:
    void reorderList(ListNode *head) {
        /* https://oj.leetcode.com/problems/reorder-list/
        L0, L1, ..., Ln-1, Ln -> L0, Ln, L1, Ln-1, ... 
        */
        
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return ;
        }
        
        ListNode *mid = findMid(head);
        ListNode *p = reverseList(mid->next);
        mid->next = NULL;
        
        while (p != NULL) {
            ListNode *tmp = p->next;
            p->next = head->next;
            head->next = p;
            head = p->next;
            p = tmp;
        }
    }
};