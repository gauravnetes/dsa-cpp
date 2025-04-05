#include<bits/stdc++.h>
using namespace std; 

class Node {
    public: 
    int data; 
    Node* next; 
    Node* back; 
    public: 
    Node(int data1, Node* next1, Node* back1) {
        data = data1; 
        next = next1;
        back = back1;  
    }

    public: 
    Node(int data1) {
        data = data1; 
        next = nullptr;
        back = nullptr;  
    }
}; 

Node* convertArrtoDLL(vector<int> &arr) {
    Node* head = new Node(arr[0], nullptr, nullptr); 
    Node* prev = head; 

    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i], nullptr, prev); 
        prev->next = temp; 
        prev = temp; // prev->next
    }
    return head; 
}

Node* deleteTheHead(Node* head) {
    if (head == NULL || head->next == NULL)
    {
        return NULL; 
    }
    Node* prev = head; 
    head = head->next; 

    head->back = nullptr; 
    prev->next = nullptr; 

    delete prev; 
    return head; 
}

Node* deleteTheTail(Node* head) {
    if (head == NULL || head->next == NULL)
    {
        return NULL; 
    }
    
    Node* tail = head; 
    while (tail->next != NULL)
    {
        tail = tail->next; 
    }
    Node* prev = tail->back; 
    tail->back = nullptr;
    prev->next = nullptr; 
    delete tail; 
    return head; 
}

Node* deleteTheKthElement(Node* head, int k) {
    // traverse to the kth element
    if (head == NULL)
    {
        return NULL; 
    }
    
    Node* temp = head;
    int cnt = 0; 
    while (temp != NULL)
    {
        cnt++; 
        if (cnt == k) break; 
        temp = temp->next; 
    }
    Node* prev = temp->back; 
    Node* front = temp->next; 

    // edge cases 
    if (prev == NULL && front == NULL)
    {
        return NULL; 
    }
    else if (prev == NULL)
    {
        return deleteTheHead(head); 
    } 
    else if (front == NULL)
    {
        return deleteTheTail(head);  
    }
    prev->next = front; 
    front->back = prev; 
    temp->next = nullptr; 
    temp->back = nullptr; 
    free(temp); 
    return head;  
}

void deleteANode(Node* temp) {
    Node* prev = temp->back; 
    Node* front = temp->next; 
    if (front == NULL)
    {
        prev->next = nullptr;
        prev->back = nullptr;  
        free(temp); 
        return; 
    }
    prev->next = front; 
    front->back = prev; 

    temp->next = temp->back = nullptr; 
    free(temp); 
}

Node* insertBeforeHead(Node* head, int val) {
    Node* newHead = new Node(val, head, nullptr); 
    head->back = newHead; 
    return newHead; 
}
void print(Node* head) {
    while (head != NULL)
    {
        cout << head->data << " "; 
        head = head->next; 
    }
    cout << endl; 
}

Node* insertBeforeTail(Node* head, int val) {
    Node* tail = head; 
    while (tail->next != NULL)
    {
        tail = tail->next; 
    }
    Node* prev = tail->back; 
    Node* newNode = new Node(val, tail, prev); 
    prev->next = newNode; 
    tail->back = newNode; 
    return head; 
}

Node* insertBeforeKthElement(Node* head, int k, int val) {
    if (k == 1)
    {
        return insertBeforeHead(head, val); 
    }
    Node* temp = head; 
    int cnt = 0; 
    while (temp->next != NULL)
    {
        cnt++; 
        if (cnt == k)
        {
            break; 
        }
        temp = temp->next; 
    }
    Node* prev = temp->back; 
    Node* newNode = new Node(val, temp, prev); 
    temp->back = newNode; 
    prev->next = newNode; 
    return head; 
}

void insertBeforeANode(Node* node, int val) {
    Node* prev = node->back; 
    Node* newNode = new Node(val, node, prev); 
    prev->next = newNode; 
    node->back = newNode; 
}

int main() { 
    vector<int> arr = {12, 5, 8, 7, 32, 42, 24}; 

    Node* head = convertArrtoDLL(arr); 
    print(head); 

    head = deleteTheHead(head); 
    print(head);

    head = deleteTheTail(head); 
    print(head); 

    head = deleteTheKthElement(head, 2); 
    print(head); 

    deleteANode(head->next); 
    print(head); 

    head = insertBeforeHead(head, 34);
    print(head);  

    head = insertBeforeTail(head, 3); 
    print(head); 

    head = insertBeforeKthElement(head, 3, 42); 
    print(head); 

    insertBeforeANode(head->next->next->next->next, 233); 
    print(head); 
    return 0; 
}