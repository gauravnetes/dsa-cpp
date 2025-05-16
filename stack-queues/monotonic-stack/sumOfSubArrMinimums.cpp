#include<bits/stdc++.h>
using namespace std; 

//  Next Smaller Element (nsE) 
vector<int> findNSE(vector<int> &arr) {
    int n = arr.size(); 
    vector<int> nsE(n); 
    stack<int> st; 
    // as next, start from the back
    for(int i = n - 1; i >= 0; i--) {
        // monotonic stack in increasing order 
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop(); 
        }
        if(st.empty()) nsE[i] = n; 
        else 
            nsE[i] = st.top(); 

        st.push(i); 
    }
    return nsE; 
}

vector<int> findPSEE(vector<int> &arr) {
    int n = arr.size();
    vector<int> psEE(n); 
    stack<int> st; 
    // as previous, starting from the front 
    for(int i = 0; i < n; i++) {
        // monotonic stack in increasing order 
        while(!st.empty() && arr[st.top()] > arr[i]) {
            st.pop(); 
        }
        psEE[i] = st.empty() ? -1 : st.top(); 

        st.push(i);  
    }
    return psEE; 
}

int sumOfSubArrMins(vector<int> &arr) {
    int n = arr.size(); 
    vector<int> nsE = findNSE(arr);
    vector<int> psEE = findPSEE(arr); 
    int total = 0; 
    int mod = (int) (1e9+7); 
    for(int i = 0; i < n; i++) {
        int left = i - psEE[i]; 
        int right = nsE[i] - i; 
        total = (total + ((left * right * arr[i] * 1LL) % mod) % mod);   
    }
    return total; 
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = sumOfSubArrMins(arr); 
    cout << sum << endl; 

    return 0;
}