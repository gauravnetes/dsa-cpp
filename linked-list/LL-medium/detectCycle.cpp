#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to rearrange linked list in odd-even order
ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while (even && even->next) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}

// Function to detect a cycle in the linked list
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// Function to insert a node at the end
void insert(ListNode*& head, int val) {
    if (!head) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new ListNode(val);
}

// Function to print the list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int n, val;
    ListNode* head = nullptr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(head, val);
    }

    cout << "Original list: ";
    printList(head);

    head = oddEvenList(head);
    cout << "Odd-Even reordered list: ";
    printList(head);

    cout << "Cycle detected: " << (hasCycle(head) ? "Yes" : "No") << endl;

    return 0;
}
