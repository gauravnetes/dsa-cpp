#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

Node *deleteAllOccurrences(Node *head, int k)
{
    if(!head) return nullptr; 
    Node* temp = head; 
    while(temp != nullptr) {
        if(temp->data == k) {
            if(temp == head) {
                head = head->next; 
            }
            Node* nextNode = temp->next; 
            Node* prevNode = temp->prev; 
            if(nextNode) nextNode->prev = prevNode; 
            if(prevNode) prevNode->next = nextNode;
            delete temp;   
            temp = temp->next; 
        } else {
            temp = temp->next; 
        }
    }
    return head; 
}

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

void printDoublyLinkedList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << (current->next ? " " : ""); // Space-separated for file output
        current = current->next;
    }
    cout << endl;
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

    Node *newHead = deleteAllOccurrences(head, k);

    printDoublyLinkedList(newHead);

    Node *current = newHead;
    while (current)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}