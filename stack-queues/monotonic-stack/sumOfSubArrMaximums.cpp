#include<bits/stdc++.h>
using namespace std; 

vector<int> findNGE(vector<int> &arr) {
    int n = arr.size(); 
    vector<int> ngE(n); 
    stack<int> st; 
    // as next, start from the back
    for(int i = n - 1; i >= 0; i--) {
        // monotonic stack in decreasing order 
        while(!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop(); 
        }
        if(st.empty()) ngE[i] = n; 
        else 
            ngE[i] = st.top();  
        
        st.push(i); 
    }
    return ngE; 
 }

//  Previous Greater Element (pgE)
vector<int> findPGEE(vector<int> &arr) {
    int n = arr.size(); 
    vector<int> pgEE(n); 
    stack<int> st; 
    // as previous, start from the front  
    for(int i = 0; i < n; i++) {
        // monotonic stack in decreasing order 
        while(!st.empty() && arr[st.top()] < arr[i]) {
            st.pop(); 
        }
        if(st.empty()) pgEE[i] = -1; 
        else 
            pgEE[i] = st.top(); 
        
        st.push(i); 
    }
    return pgEE; 
 }


int sumOfSubArrMaxs(vector<int> &arr) {
    int n = arr.size(); 
    vector<int> ngE = findNGE(arr);
    vector<int> pgEE = findPGEE(arr); 
    int total = 0; 
    int mod = (int) (1e9+7); 
    for(int i = 0; i < n; i++) {
        int left = i - pgEE[i]; 
        int right = ngE[i] - i; 
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

    int sum = sumOfSubArrMaxs(arr); 
    cout << sum << endl; 

    return 0;
}