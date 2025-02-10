#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrixBy90Deg(vector<vector<int>> &matrix)
{
    int m = matrix.size(); 
        int n = matrix[0].size(); 
        for(int i = 0; i < m; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]); 
            }
        }
        for(int i = 0; i < m; i++) {
            reverse(matrix[i].begin(), matrix[i].end()); 
        }
        return matrix; 
}

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        int m, n;
        cin >> m >> n; // Read matrix dimensions

        vector<vector<int>> matrix(m, vector<int>(n)); // Create a 2D matrix

        // Read the matrix input
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }

        // Apply the function on the matrix
        rotateMatrixBy90Deg(matrix);

        // Print the modified matrix
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl; // Move to the next row
        }
    }

    return 0;
}
