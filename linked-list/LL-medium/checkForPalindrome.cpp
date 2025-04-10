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
    ListNode* reverseLL(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseLL(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second != NULL) {
            if(first->val != second->val) {
                reverseLL(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL(newHead);
        return true;
    }
};

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
    cout << (sol.isPalindrome(head) ? "true" : "false") << endl;
    return 0;
}
