//https://oj.leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        
        while (head && head->next) {
            ListNode *tmp = head->next->next;
            tail->next = head->next;
            tail->next->next = head;
            tail = head;
            head = tmp;
        }
        
        tail->next = head;
        head = dummy->next;
        delete dummy;
        
        return head;
    }
};