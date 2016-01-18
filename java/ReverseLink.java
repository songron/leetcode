/**
 * Created by sooglejay on 16/1/16.
 */
public class Solution {
    //Assume that we have linked list 1 → 2 → 3 → Ø, we would like to change it to Ø ← 1 ← 2 ← 3

    /**
     * efficient solution
     *
     * @param head
     * @return
     */
    public ListNode reverseList1(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode p = reverseList1(head.next);
        head.next.next = head;
        head.next = null;
        return p;
    }

    /**
     * efficient solution
     *
     * tips:
     * While you are traversing the list,
     * change the current node's next pointer to point to its previous element
     * @param head
     * @return
     */
    public ListNode reverseList2(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    /**
     * inefficient solution
     *
     * @param head
     * @return
     */
    public static ListNode reverseList3(ListNode head) {
        int size = 0;
        ListNode tempNode = head;
        //get the size of the list
        while (tempNode != null) {
            size++;
            tempNode = tempNode.next;
        }
        if (size < 2) {
            return head;
        }
        //data array to store each value of each node
        int data[] = new int[size];
        while (head != null) {
            data[--size] = head.val;//store array elements from end to start
            head = head.next;
        }

        ListNode footer = new ListNode(data[0]);
        head = footer;
        //recreate a new list
        for (int j = 1; j < data.length; j++) {
            ListNode node = new ListNode(data[j]);
            footer.next = node;
            footer = footer.next;
        }
        return head;
    }

}

/**
 * Created by sooglejay on 16/1/16.
 */
private static class ListNode {

    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }

    @Override
    public String toString() {
        return "ListNode{" +
                "val=" + val +
                ", next=" + next +
                '}';
    }


}
