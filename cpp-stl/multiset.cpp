#include<bits/stdc++.h>
using namespace std; 

int main() {
    // operations are same as set 
    // only stores duplicate elements also

    multiset<int>ms; 
    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}

    ms.erase(1); // all 1s erased

    int cnt = ms.count(1); 

    ms.erase(ms.find(1)); // first occurance of 1 is erased

    ms.erase(ms.find(1), ms.find(1) + 2); 
}