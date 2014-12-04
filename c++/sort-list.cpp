//https://oj.leetcode.com/problems/sort-list/

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
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *mid = findMid(head);
        ListNode *right = sortList(mid->next);
        mid->next = NULL;
        ListNode *left = sortList(head);
        
        return mergeTwoList(left, right);
    }
    
    ListNode *findMid(ListNode *head) {
        assert(head != NULL && head->next != NULL);
        ListNode *slow = head, *fast = head->next;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode *mergeTwoList(ListNode *left, ListNode *right) {
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        
        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            }
            else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        
        if (left != NULL) tail->next = left;
        if (right != NULL) tail->next = right;
        
        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }
};