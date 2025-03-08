#include <bits/stdc++.h>
using namespace std;
int rowWithMax1s(vector<vector<int>> &arr) {
    // code here
    int n = arr.size(); 
    int m = arr[0].size(); 
    int cntMax = 0; 
    int index = -1;  
    for(int i = 0; i < n; i++) {
        auto it = lower_bound(arr[i].begin(), arr[i].end(), 1); 
        int cntOnes = m - (it - arr[i].begin()); 
        if(cntOnes > cntMax) {
            cntMax = cntOnes; 
            index = i; 
        }
    }
    return index; 
}

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m; // Read dimensions of the matrix

        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j]; // Read matrix elements
            }
        }

        int maxRowIndex = rowWithMax1s(arr);
        cout << maxRowIndex << endl; // Output result for the test case
    }

    return 0;
}