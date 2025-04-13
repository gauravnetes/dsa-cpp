#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

Node *addTwoLL(Node *l1, Node *l2)
{
    Node *t1 = l1;
    Node *t2 = l2;
    Node *dummyNode = new Node(-1);
    Node *curr = dummyNode;
    int carry = 0;
    while (t1 != nullptr || t2 != nullptr || carry)
    {
        int sum = carry;
        if (t1)
        {
            sum += t1->data;
            t1 = t1->next;
        }
        if (t2)
        {
            sum += t2->data;
            t2 = t2->next;
        }
        curr->next = new Node(sum % 10);
        carry = sum / 10;
        curr = curr->next;
    }
    return dummyNode->next;
}

// Helper function to create a linked list from a vector
Node *createList(const vector<int> &nums)
{
    if (nums.empty())
    {
        return nullptr;
    }
    Node *head = new Node(nums[0]);
    Node *tail = head;
    for (size_t i = 1; i < nums.size(); ++i)
    {
        Node *newNode = new Node(nums[i]);
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << (current->next ? " " : "");
        current = current->next;
    }
    cout << endl;
}

int main()
{
    int n1, n2;
    cin >> n1;
    vector<int> values1(n1);
    for (int i = 0; i < n1; ++i)
    {
        cin >> values1[i];
    }
    Node *l1 = createList(values1);

    cin >> n2;
    vector<int> values2(n2);
    for (int i = 0; i < n2; ++i)
    {
        cin >> values2[i];
    }
    Node *l2 = createList(values2);

    Node *resultHead = addTwoLL(l1, l2);
    printList(resultHead);

    // Memory management
    Node *curr = resultHead;
    while (curr)
    {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
    Node *c1 = l1;
    while (c1)
    {
        Node *next = c1->next;
        delete c1;
        c1 = next;
    }
    Node *c2 = l2;
    while (c2)
    {
        Node *next = c2->next;
        delete c2;
        c2 = next;
    }

    return 0;
}