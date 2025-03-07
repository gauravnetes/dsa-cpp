#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{ 
    int m = matrix.size();  // row length
    int n = matrix[0].size(); // col length
    vector<int> row(m, 0); 
    vector<int> col(n, 0); 

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1; 
                col[j] = 1; 
            }   
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0; 
            }
            
        }
        
    }
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
        setZeroes(matrix);

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
