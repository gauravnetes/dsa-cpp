#include<bits/stdc++.h>
using namespace std; 

int main() {
    stack<int> st; 
    st.push(1); // {1}
    st.push(2); // {2, 1}
    st.push(3); // {3, 2, 1}
    st.emplace(4); // {4, 3, 2, 1}

    cout << st.top(); // 5
    st.pop();  // st looks like {3 2 1}
    cout << st.top(); // 3
    cout << st.size(); // 3
    cout << st.empty();

    stack<int>st1, st2; 
    st1.swap(st2);

}