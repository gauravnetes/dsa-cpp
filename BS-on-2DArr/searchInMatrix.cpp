#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = m * n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / n;
        int col = mid % n;

        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int m, n, target;
        cin >> m >> n; // Matrix dimensions
        vector<vector<int>> matrix(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j]; // Read matrix elements
            }
        }

        cin >> target; // Read the target element

        bool found = searchMatrix(matrix, target);
        cout << (found ? "true" : "false") << endl;
    }

    return 0;
}
