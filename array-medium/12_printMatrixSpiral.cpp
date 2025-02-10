#include <bits/stdc++.h>
using namespace std;

vector<int> printMatrixSpiral(vector<vector<int>> &matrix)
{
    int m = matrix.size(); 
        int n = matrix[0].size(); 
        int left = 0, right = n - 1; 
        int top = 0, bottom = m - 1; 
        vector<int> result; 

        while(top <= bottom && left <= right) {
            // right
            for(int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);  
            }
            top++;
            // bottom
            for(int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);  
            }
            right--;
            
            if(top <= bottom) {
                // left
                for(int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]); 
                }
                bottom--; 
            }
            if(left <= right) {
                // top
                for(int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]); 
                }
                left++; 
            }
        }
        return result; 
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
        vector<int> matrixSpiral = printMatrixSpiral(matrix);

        // Print the modified matrix
        for(int i = 0; i < matrixSpiral.size(); i++) {
            cout << matrixSpiral[i] << " "; 
        }
    }

    return 0;
}
