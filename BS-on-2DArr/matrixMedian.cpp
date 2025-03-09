#include<bits/stdc++.h>
using namespace std; 

int countSmallEqual(vector<vector<int>> &mat, int x) {
    int n = mat.size(); 
    int cnt = 0; 
    for(int i = 0; i < n; i++) {
        cnt += upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin(); 
    }
    return cnt; 
}
int median(vector<vector<int>> &mat) {
    // code here
    int low = INT_MAX; 
    int high = INT_MIN;
    int n = mat.size(); 
    int m = mat[0].size(); 
    for(int i = 0; i < n; i++) {
        low = min(low, mat[i][0]); 
        high = max(high, mat[i][m - 1]); 
    }
    int req = (n * m) / 2; 
    while(low <= high) {
        int mid = (low + high) / 2; 
        int smallEqual = countSmallEqual(mat, mid); 
        if(smallEqual <= req) low = mid + 1; 
        else high = mid - 1; 
    }
    return low; 
}

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m; // Read dimensions of the matrix

        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j]; // Read matrix elements
            }
        }

        cout << median(mat) << endl; // Output median of the matrix
    }

    return 0;
}