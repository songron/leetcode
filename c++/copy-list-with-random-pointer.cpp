//https://oj.leetcode.com/problems/copy-list-with-random-pointer/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
private:
    void copyAndInsert(RandomListNode *head)
    {
        RandomListNode *p = head;
        while (p != NULL) {
            RandomListNode *tmp = new RandomListNode(p->label);
            tmp->next = p->next;
            p->next = tmp;
            p = tmp->next;
        }
    }
    
    void copyRandomPointer(RandomListNode *head)
    {
        RandomListNode *p = head;
        while (p != NULL) {
            if (p->random != NULL) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
    }
    
    RandomListNode *splitCopiedList(RandomListNode *head)
    {
        RandomListNode *copiedHead = head->next;
        RandomListNode *tail = head, *copiedTail = copiedHead;
        
        while (copiedTail->next != NULL) {
            tail->next = copiedTail->next;
            tail = tail->next;
            copiedTail->next = copiedTail->next->next;
            copiedTail = copiedTail->next;
        }
        tail->next = NULL;
        
        return copiedHead;
        
    }

public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        
        copyAndInsert(head);
        copyRandomPointer(head);
        return splitCopiedList(head);
    }
};