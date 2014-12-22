# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def insertionSortList(self, head):
        if not head or not head.next:
            return head

        dummy = ListNode(-1)
        dummy.next = head
        cur = head.next
        while cur:
            print cur.val
            p = dummy
            while p.next and p.next.val < cur.val:
                p = p.next

            t = cur.next
            cur.next = p.next
            p.next = cur
            cur = t

        head = dummy.next
        del dummy
        return head


l = ListNode(1)
l.next = ListNode(1)
s = Solution()
r = s.insertionSortList(l)
#while r:
#    print r.val
#    r = r.next
