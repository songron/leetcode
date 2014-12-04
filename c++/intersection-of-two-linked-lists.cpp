//https://oj.leetcode.com/problems/intersection-of-two-linked-lists/

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
    int moveToTail(ListNode *&head) {
        if (head == NULL) {
            return 0;
        }
        
        int len = 1;
        while (head->next != NULL) {
            head = head->next;
            ++len;
        }
        
        return len;
    }

    ListNode *move(ListNode *node, int k) {
        while (k-- > 0) {
            node = node->next;
        }
        return node;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // if two linked lists have intersection, thay share the same tail-node.
        
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        
        ListNode *tailA = headA;
        int lenA = moveToTail(tailA);

        ListNode *tailB = headB;
        int lenB = moveToTail(tailB);
        
        if (lenA > lenB) {
            headA = move(headA, lenA - lenB);
        }
        else {
            headB = move(headB, lenB - lenA);
        }
        
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};