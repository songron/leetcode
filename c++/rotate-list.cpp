//https://oj.leetcode.com/problems/rotate-list/

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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;
        
        ListNode *tail = head;
        int len = 1;
        while (tail->next != NULL) {
            len++;
            tail = tail->next;
        }
        
        k = k % len;
        if (k == 0) return head;
        
        ListNode *tmp = head;
        for (int i = 1; i < len - k; i++) {
            tmp = tmp->next;
        }
        
        tail->next = head;
        head = tmp->next;
        tmp->next = NULL;
        
        return head;
    }
};