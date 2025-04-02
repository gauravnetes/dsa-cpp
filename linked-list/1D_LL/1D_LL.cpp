#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Convert an array to a linked list
Node *convertArrToLL(vector<int> &arr)
{
    if (arr.empty())
        return nullptr; // Handle empty array case

    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Find length of the linked list
int lengthOfLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

// Search for an element
bool searchAnElement(Node *head, int val)
{ // Changed return type to bool
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}

// Print linked list
void printLL(Node *head)
{
    if (!head)
    {
        cout << "Linked list is empty." << endl;
        return;
    }
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Remove head node
Node *removeHead(Node *head)
{
    if (!head)
        return nullptr; // If LL is empty
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *removeTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* removeK(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head; 
}

Node* removeEl(Node* head, int el) {
    if(head == NULL) return head; 
    if (head->data == el)
    {
        Node* temp = head; 
        head = head->next; 
        free(temp); 
    }
    // as we know the element we don't need to track count remove the first node with that element. linear search
    Node* temp = head; 
    Node* prev = NULL; 
    while (temp != NULL)
    {
        if (temp->data == el)
        {
            prev->next = prev->next->next; 
            free(temp); 
            break; 
        }
        prev = temp; 
        temp = temp->next; 
    }
    return head; 
    
}

Node* insertHead(Node* head, int val) {
    Node* temp = new Node(val, head); // the temp should be pointing towards head 
    return temp; 
}

Node* insertTail(Node* head, int val) {
    if(head == NULL) return new Node(val); 

    Node* temp = head; 
    while(temp->next != NULL) {
        temp = temp->next; 
    }
    Node* newNode = new Node(val); // points to NULL
    temp->next = newNode; 
    return head; 
}

Node* insertAtPos(Node* head, int el, int k) {
    if (head == NULL)
    {
        if (k == 1)
        {
            return new Node(el); 
        } else {
            return head; 
        }
    }

    if(k == 1) {
        return new Node(el, head); 
    }

    int cnt = 0; 
    Node* temp = head;
    while (temp != NULL)
    {
        cnt++; 
        if (cnt == k - 1)
        {
            Node* x = new Node(el, temp->next); // new node with data = x and next will pointing to the temp->next
            // x->next = temp->next; 
            temp->next = x; 
            break; 
        }
        temp = temp->next; 
    }
    return head; 
}

Node* insertBeforeVal(Node* head, int el, int val) {
    // empty LL with no value to insert before
    if (head == NULL)
    {
        return NULL; 
    }

    if(head->data == val) {
        return new Node(el, head); 
    }

    Node* temp = head;
    // traverse until the second last element 
    while (temp->next != NULL)
    {
        if (temp->next->data == val)
        {
            Node* x = new Node(el, temp->next); // new node with data = x and next will pointing to the temp->next
            // x->next = temp->next; 
            temp->next = x; 
            break; 
        }
        temp = temp->next; 
    }
    return head; 
}

int main() 
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = convertArrToLL(arr);

    head = insertHead(head, 100); 
    printLL(head); 

    head = insertTail(head, 53); 
    printLL(head); 

    head = insertAtPos(head, 30, 2); 
    printLL(head); 

    head = insertBeforeVal(head, 2333, 7); 
    printLL(head); 

    head = removeK(head, 3); 
    printLL(head);

    head = removeEl(head, 5); 
    printLL(head); 

    head = removeTail(head);
    printLL(head);

    head = removeHead(head);
    printLL(head);

    // Ensure head is not nullptr before accessing data
    if (head)
    {
        cout << "Head data: " << head->data << endl;
    }
    else
    {
        cout << "Head is null after removal." << endl;
    }

    // Demonstrating pointer object
    Node *y = new Node(arr[0], nullptr);
    cout << "Pointer node data: " << y->data << " Next: " << y->next << endl;

    // Demonstrating normal object
    Node y1(arr[0], nullptr);
    cout << "Normal node data: " << y1.data << " Next: " << y1.next << endl;

    // Traversing the linked list
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Length of linked list
    int len = lengthOfLL(head);
    cout << "Length of LL: " << len << endl;

    // Search an element
    bool present = searchAnElement(head, 7);
    cout << "Is 7 present? " << (present ? "Yes" : "No") << endl;

    return 0;
}
