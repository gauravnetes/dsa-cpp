#include<bits/stdc++.h>
using namespace std;  

int maxElement(vector<vector<int>>& mat, int n, int m, int col) {
    int index = -1;
    int maxEl = -1;
    for (int i = 0; i < n; i++) {
        if (mat[i][col] > maxEl) {
            maxEl = mat[i][col];
            index = i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = maxElement(mat, n, m, mid);
        int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
        int right = mid + 1 < m ? mat[row][mid + 1] : -1;
        if (mat[row][mid] > left && mat[row][mid] > right) {
            return {row, mid};
        } else if (mat[row][mid] < left) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return {-1, -1};
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

        vector<int> peak = findPeakGrid(mat);
        cout << peak[0] << " " << peak[1] << endl; // Output peak element position
    }

    return 0;
}