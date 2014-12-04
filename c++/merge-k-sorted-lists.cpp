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
    class Comp {
    public:
        bool operator() (const ListNode *l1, const ListNode *l2) {
            return l1->val > l2->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        /* https://oj.leetcode.com/problems/merge-k-sorted-lists/
        Use a priority_queue (min-heap);
        T = sum_of_lengths * log(k)
        */
        
        if (lists.empty()) return NULL;
        
        ListNode *dummy = new ListNode(0), *tail = dummy;
        priority_queue<ListNode*, vector<ListNode*>, Comp> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) pq.push(lists[i]);
        }
        
        while (!pq.empty()) {
            ListNode *tmp = pq.top();
            pq.pop();
            if (tmp->next) pq.push(tmp->next);
            tail->next = tmp;
            tail = tail->next;
        }
        
        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }
};