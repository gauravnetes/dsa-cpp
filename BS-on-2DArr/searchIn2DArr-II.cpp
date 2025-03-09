#include <bits/stdc++.h>
using namespace std;

int n = matrix.size();
int m = matrix[0].size();
int row = 0, col = m - 1;
while (row < n && col >= 0)
{
    if (matrix[row][col] == target)
    {
        return true;
    }
    else if (matrix[row][col] < target)
    {
        row++;
    }
    else
    {
        col--;
    }
}
return false;

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        int n, m, target;
        cin >> n >> m; // Read dimensions of the matrix

        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j]; // Read matrix elements
            }
        }

        cin >> target; // Read the target element

        if (searchMatrix(matrix, target))
        {
            cout << "1" << endl; // Target found
        }
        else
        {
            cout << "0" << endl; // Target not found
        }
    }

    return 0;
}