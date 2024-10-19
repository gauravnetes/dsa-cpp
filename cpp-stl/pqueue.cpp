#include<bits/stdc++.h>
using namespace std; 

int main() {
    // max heap
    priority_queue<int>pq;  // largest value stays at the top

    pq.push(5); // {5}
    pq.push(2); // {5, 2}
    pq.push(8); // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << pq.top(); // 10

    pq.pop(); // {8, 5, 2}

    // minimum heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); // {5}
    pq.push(2); // {2, 5}
    pq.push(8); // {2 ,5, 8}
    pq.emplace(10); // {2, 5, 8, 10}

    cout << pq.top(); // 2
}

// Time Complexity:
// push/pop => logn  top => O(1)