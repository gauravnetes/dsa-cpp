#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int col0 = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 1;
                }
            }
        }
    }
    // iterate without the 0th row and column. special case for those
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                if (!matrix[i][0] || !matrix[0][j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // now for the 0th row and col
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0; // row remains constant
            // the entire col becomes zero for the given condition
        }
    }

    if (col0 == 1)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
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
