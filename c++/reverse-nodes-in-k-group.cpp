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
    ListNode *reverseKGroup(ListNode *head, int k) {
        /* https://oj.leetcode.com/problems/reverse-nodes-in-k-group/
        e.g.,
        Given this linked list: 1->2->3->4->5
        For k = 2, you should return: 2->1->4->3->5
        For k = 3, you should return: 3->2->1->4->5
        */
        
        if (head == NULL || head->next == NULL || k < 2) return head;
        
        ListNode *dummy = new ListNode(0), *tail = dummy;
        
        while (head != NULL) {
            ListNode *tmp = head;
            for (int i = 1; i < k && tmp != NULL; i++) {
                tmp = tmp->next;
            }
            if (tmp == NULL) {
                tail->next = head;
                break;
            }
            
            ListNode *tmp2 = tmp->next;
            tmp->next = NULL;
            reverseList(head);
            tail->next = tmp;
            tail = head;
            head = tmp2;
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }
};