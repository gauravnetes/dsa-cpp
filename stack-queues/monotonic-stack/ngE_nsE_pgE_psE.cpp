#include<bits/stdc++.h>
using namespace std; 

// Next Greater Element (ngE)
vector<int> findNGE(vector<int> &arr) {
    int n = arr.size(); 
    vector<int> ngE(n); 
    stack<int> st; 
    // as next, start from the back
    for(int i = n - 1; i >= 0; i--) {
        // monotonic stack in decreasing order 
        while(!st.empty() && st.top() <= arr[i]) {
            st.pop(); 
        }
        if(st.empty()) ngE[i] = -1; 
        else 
            ngE[i] = st.top();  
        
        st.push(arr[i]); 
    }
    return ngE; 
 }

//  Previous Greater Element (pgE)
vector<int> findPGE(vector<int> &arr) {
    int n = arr.size(); 
    vector<int> pgE(n); 
    stack<int> st; 
    // as previous, start from the front  
    for(int i = 0; i < n; i++) {
        // monotonic stack in decreasing order 
        while(!st.empty() && st.top() <= arr[i]) {
            st.pop(); 
        }
        if(st.empty()) pgE[i] = -1; 
        else 
            pgE[i] = st.top(); 
        
        st.push(arr[i]); 
    }
    return pgE; 
 }

//  Next Smaller Element (nsE) 
vector<int> findNSE(vector<int> &arr) {
    int n = arr.size(); 
    vector<int> nsE(n); 
    stack<int> st; 
    // as next, start from the back
    for(int i = n - 1; i >= 0; i--) {
        // monotonic stack in increasing order 
        while(!st.empty() && st.top() >= arr[i]) {
            st.pop(); 
        }
        if(st.empty()) nsE[i] = -1; 
        else 
            nsE[i] = st.top(); 

        st.push(arr[i]); 
    }
    return nsE; 
}

vector<int> findPSE(vector<int> &arr) {
    int n = arr.size();
    vector<int> psE(n); 
    stack<int> st; 
    // as previous, starting from the front 
    for(int i = 0; i < n; i++) {
        // monotonic stack in increasing order 
        while(!st.empty() && st.top() >= arr[i]) {
            st.pop(); 
        }
        if(st.empty()) psE[i] = -1; 
        else 
            psE[i] = st.top(); 

        st.push(arr[i]); 
    }
    return psE; 
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> nge = findNGE(arr); 
    for (size_t i = 0; i < nge.size(); i++)
    {
        cout << nge[i] << " "; 
    }
    cout << endl; 

    vector<int> pge = findPGE(arr); 
    for(size_t i = 0; i < pge.size(); i++) {
        cout << pge[i] << " "; 
    }
    cout << endl;

    vector<int> nse = findNSE(arr); 
    for(size_t i = 0; i < nse.size(); i++) {
        cout << nse[i] << " "; 
    }
    cout << endl; 

    vector<int> pse = findPSE(arr); 
    for(size_t i = 0; i < pse.size(); i++) {
        cout << pse[i] << " "; 
    }
    cout << endl; 

    return 0;
}