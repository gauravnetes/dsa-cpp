#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node() : data(0), prev(NULL), next(NULL) {}
    Node(int data) : data(data), prev(NULL), next(NULL) {}
    Node(int data, Node *next, Node *prev) : data(data), prev(prev), next(next) {}
};

Node* findTail(Node* head) {
    Node *tail = head; 
    while(tail->next != nullptr) {
        tail = tail->next; 
    }
    return tail; 
}
vector<pair<int, int>> findPairs(Node *head, int k)
{
    vector<pair<int, int>> ans;
    if(head == nullptr) return ans;  
    Node* left = head; 
    Node* right = findTail(head);
    while(left->data < right->data) {
        if(left->data + right->data == k) {
            ans.push_back({ left->data, right->data }); 
            left = left->next;
            right = right->prev;  
        }
        else if (left->data + right->data < k)
        {
            left = left->next; 
        } else {
            right = right->prev; 
        }
    }
    return ans; 
}

// Helper function to create a doubly linked list from a vector
Node *createDoublyLinkedList(const vector<int> &nums)
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
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

void printPairs(const vector<pair<int, int>> &pairs)
{
    for (const auto &pair : pairs)
    {
        cout << pair.first << " " << pair.second << endl;
    }
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    Node *head = createDoublyLinkedList(values);

    cin >> k;

    vector<pair<int, int>> pairs = findPairs(head, k);
    printPairs(pairs);

    // Memory management
    Node *current = head;
    while (current)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}