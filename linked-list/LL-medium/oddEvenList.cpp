#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head; 

        ListNode* odd = head; 
        ListNode* even = head->next; 
        ListNode* evenHead = head->next; 

        while(even != nullptr && even->next != nullptr) {
            odd->next = even->next; 
            odd = odd->next;

            even->next = odd->next;
            even = even->next;  
        }

        odd->next = evenHead; // Connect odd list with even list
        return head; 
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val;
        if(head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if(head == nullptr) {
            head = new ListNode(val);
            tail = head;
        } else {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
    }

    Solution sol;
    head = sol.oddEvenList(head);

    printList(head);

    return 0;
}
