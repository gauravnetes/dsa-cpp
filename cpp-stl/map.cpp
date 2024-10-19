#include<bits/stdc++.h>
using namespace std; 

int main() {
    map<int, int> mpp; 
    map<int, pair<int, int>> mpp; 

    // map stores unique keys in sorted order. just like set ds

    mpp[1] = 2; 
    mpp.emplace({3, 1}); 
    mpp.insert({2, 4});

    mpp[{2, 3}] = 10; 

    {
        {1, 2}
        {2, 4}
        {3, 1}
    }

    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl; 
    }

    auto it = mpp.find(3); 
    cout << *(it).second;  

// other operations are same

    // Multimaps:
    // can store duplicate keys in sorted order O(logn)

    // unordered maps:
    // not in sorted order O(1)
}