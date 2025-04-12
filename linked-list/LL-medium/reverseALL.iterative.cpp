#include <iostream>
using namespace std;

// Definition of the linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse the linked list iteratively
Node* reverseList(Node* head) {
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr) {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// 1st
// 3 - 4 - 5 - 6 - x
// temp = 3 
// prev = nullptr
// front = 4
// 3 -> next = nullptr
// prev = 3
// temp = 4 

// 2nd
// temp = 4
// front = 5
// 4 -> next = 3
// prev = 4
// temp = 5

// 3rd 
// temp = 5
// front = 6
// 5 -> next = 4
// prev = 5
// temp = 6

// 4th
// temp = 6
// fornt = x
// 6->next = 5
// prev = 6
// temp = x

// return 6 -> head of the reversed LL

// Function to insert a node at the end of the linked list
void insert(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int n, val;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(head, val);
    }
    
    printList(head);
    
    head = reverseList(head);
    
    printList(head);
    
    return 0;
}
