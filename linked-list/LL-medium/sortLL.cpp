#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Find middle node
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    
    while (list1 && list2) {
        if (list1->val < list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    
    if (list1) temp->next = list1;
    else temp->next = list2;
    
    return dummy->next;
}

// Sort linked list using Merge Sort
ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    
    ListNode* middle = findMiddle(head);
    ListNode* right = middle->next;
    middle->next = nullptr;
    
    ListNode* left = head;
    
    left = sortList(left);
    right = sortList(right);
    
    return mergeTwoLists(left, right);
}

// Create linked list from vector
ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    
    ListNode* head = new ListNode(nums[0]);
    ListNode* tail = head;
    for (int i = 1; i < nums.size(); ++i) {
        tail->next = new ListNode(nums[i]);
        tail = tail->next;
    }
    return head;
}

// Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " " : "");
        head = head->next;
    }
    cout << endl;
}

// Free linked list memory
void freeList(ListNode* head) {
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    
    ListNode* head = createList(values);
    ListNode* sortedHead = sortList(head);
    
    printList(sortedHead);
    
    freeList(sortedHead);

    return 0;
}
