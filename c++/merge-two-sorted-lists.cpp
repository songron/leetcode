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
   struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* findMid(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;

    Node* ans = new Node(0); // dummy node
    Node* temp = ans;

    while (left != nullptr && right != nullptr) {
        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != nullptr) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != nullptr) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = nullptr;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
};
