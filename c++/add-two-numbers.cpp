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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        /* https://oj.leetcode.com/problems/add-two-numbers/
        (2,4,3) + (5,6,4) = (7,0,8)
        most significant number is on the tail.
        */
        
        ListNode *dummy = new ListNode(0), *tail = dummy;
        int carry = 0;
        
        while (l1 || l2) {
            int x = carry;
            if (l1) {
                x += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                x += l2->val;
                l2 = l2->next;
            }
            
            tail->next = new ListNode(x % 10);
            tail = tail->next;
            carry = x / 10;
        }
        
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        
        l1 = dummy->next;
        delete dummy;
        
        return l1;
    }
};