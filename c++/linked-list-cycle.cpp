//https://oj.leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode *head) {
       // we cannot reach "NULL" if there is a cycle !
       
       if (head == NULL || head->next == NULL) {
           return false;
       }
       
       ListNode *slow = head, *fast = head->next;
       
       while (fast != NULL && fast->next != NULL && slow != fast) {
           fast = fast->next->next;
           slow = slow->next;
       }
       
       return (fast != NULL && fast->next != NULL);
       
    }
};