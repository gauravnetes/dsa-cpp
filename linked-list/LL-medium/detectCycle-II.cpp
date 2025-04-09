#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head; 
        ListNode* fast = head; 
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next; 
            fast = fast->next->next;
            if(slow == fast) {
                slow = head; 
                while(slow != fast) {
                    slow = slow->next; 
                    fast = fast->next; 
                }
                return slow; 
            }
        }
        return NULL; 
    }
};

void printCycleStart(ListNode* node) {
    if (node) cout << node->val << endl;
    else cout << -1 << endl;
}

int main() {
    int n, pos;
    cin >> n >> pos;

    if (n == 0) {
        cout << -1 << endl;
        return 0;
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode* cycleEntry = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (!head) head = newNode;
        else tail->next = newNode;
        tail = newNode;
        if (i == pos) cycleEntry = newNode;
    }

    if (cycleEntry) tail->next = cycleEntry;

    Solution solution;
    ListNode* cycleStart = solution.detectCycle(head);
    printCycleStart(cycleStart);

    return 0;
}
