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
    ListNode *findKthNode(ListNode *head, int k) {
        for (int i = 1; i < k; i++) {
            head = head->next;
        }
        return head;
    }
    
    void reverseList(ListNode *head) {
        ListNode *newHead = NULL;
        while (head != NULL) {
            ListNode *tmp = head->next;
            head->next = newHead;
            newHead = head;
            head = tmp;
        }
    }

public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        /* https://oj.leetcode.com/problems/reverse-linked-list-ii/
        In one pass: split out the sub-list(form m to n), 
        reverse the sub-list, then insert it back.
        */
        
        if (head == NULL || head->next == NULL || m == n) {
            return head;
        }
        
        ListNode *leftTail = NULL, *midHead = NULL, *midTail = NULL;
        if (m == 1) {
            midHead = head;
        }
        else {
            leftTail = findKthNode(head, m-1);
            midHead = leftTail->next;
            leftTail->next = NULL;
        }
        
        midTail = findKthNode(midHead, n-m+1);
        ListNode *rightHead = midTail->next;
        midTail->next = NULL;
        reverseList(midHead);
        
        if (leftTail == NULL) {
            head = midTail;
        }
        else {
            leftTail->next = midTail;
        }
        midHead->next = rightHead;
        return head;
    }
};