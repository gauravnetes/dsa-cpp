#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

Node *reverseList(Node *head)
{
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// 1 - 5 - 9
// reverse 
// 9 - 5 - 1
// 1st:
// head = 9
// carry = 1
// temp = 9
// temp->data = 9 + 1 = 10
// else:   temp->data = 0
//         carry = 1

Node *addOnetoLL(Node *head)
{
    if(!head) return new Node(1); 
    head = reverseList(head);
    Node* temp = head;  
    int carry = 1; 

    while (temp != nullptr)
    {
        temp->data = temp->data + carry; 
        if(temp->data < 10) {
            carry = 0; 
            break;
        } else {
            temp->data = 0; 
            carry = 1; 
        }
        temp = temp->next; 
    }
    if(carry == 1) {
        Node* newNode = new Node(1); 
        head = reverseList(head); 
        newNode->next = head; 
        return newNode; 
    }
    head = reverseList(head);
    return head; 
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
    int n;
    cin >> n; // Read the number of nodes from input.txt

    if (n < 0)
    {
        return 1; // Indicate an error, but no message to output.txt
    }

    vector<int> values(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i]; // Read the values from input.txt
    }

    Node *head = createList(values);

    Node *resultHead = addOnetoLL(head);

    printList(resultHead); // Print the result to stdout, which will be redirected to output.txt

    // Memory management (simplified)
    Node *current = resultHead;
    while (current)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}