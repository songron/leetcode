//https://oj.leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        
        ListNode *slow = head, *fast = head;
        
        do {
            slow = slow->next;
            fast = fast->next->next;
                
        } while(fast != NULL && fast->next != NULL && slow != fast);
        
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }
        
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        
        return head;
    }
};