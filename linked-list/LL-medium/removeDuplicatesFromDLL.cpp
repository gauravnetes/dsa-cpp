#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

Node *removeDuplicates(Node *head) {
    Node *temp = head; 
    if (!head) {
        return nullptr;
    }
    while (temp != nullptr && temp->next != nullptr) 
    {
        Node *nextNode = temp->next; 
        while (nextNode != nullptr && nextNode->data == temp->data)
        {
            Node *duplicate = nextNode; 
            nextNode = nextNode->next; 
            free(duplicate); 
        }
        temp->next = nextNode; 
        if(nextNode) nextNode->prev = temp; 
        temp = temp->next; 
    }
    return head;  
}

Node *createDoublyLinkedList(const vector<int> &nums) {
    if (nums.empty()) {
        return nullptr;
    }
    Node *head = new Node(nums[0]);
    Node *tail = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        Node *newNode = new Node(nums[i]);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

void printDoublyLinkedList(Node *head) {
    Node *current = head;
    while (current) {
        cout << current->data << (current->next ? " " : "");
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    Node *head = createDoublyLinkedList(values);

    Node *newHead = removeDuplicates(head);

    printDoublyLinkedList(newHead);

    Node *current = newHead;
    while (current) {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}