#include<bits/stdc++.h>
using namespace std;

int main() {
    set<int>st;     // will insert only the unique numbers. won't insert the same number twice in the same set
    st.insert(1); // {1}
    st.emplace(2);  // {1, 2}
    st.insert(2);   // {1, 2}
    st.insert(4);   // {1, 2, 4}
    st.insert(3);   // {1, 2, 3, 4} -> stores in a sorted order

    // {1, 2, 3, 4, 5}
    auto it = st.find(3); // returns an iterator which points to the 3

    // {1, 2, 3, 4, 5}
    auto it = st.find(6); // return set.end()
    
    st.erase(5) // delete 5, maintains the sorted order

    int cnt = st.count(1);

    auto it = st.find(3);
    st.erase(it);

    auto it = st.lower_bound(2); // returns first element equal or greater than the given value
    auto it = st.upper_bound(3); // returns first element strictly greater than the given value

// Time complexiety: O(logn)


}