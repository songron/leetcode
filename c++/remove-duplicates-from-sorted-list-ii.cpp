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
    ListNode *deleteDuplicates(ListNode *head) {
        /* https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
        Leaving only distinct numbers from the original list.
        1, 1, 1, 2, 3 -> 2, 3
        */
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *dummy = new ListNode(0);  // head is not fixed, use a dummy node
        dummy->next = head;
        ListNode *p = dummy;
        
        while (p->next != NULL && p->next->next != NULL) {
            if (p->next->val == p->next->next->val) {  // found duplicates
                int v = p->next->val;
                while (p->next != NULL && p->next->val == v) {
                    ListNode *tmp = p->next->next;
                    delete p->next;
                    p->next = tmp;
                }
            }
            else {  // p->next is safe
                p = p->next;
            }
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }
};