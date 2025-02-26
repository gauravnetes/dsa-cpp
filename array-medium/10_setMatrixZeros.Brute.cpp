#include <bits/stdc++.h>
using namespace std;


void markRow(vector<vector<int>> & matrix, int i) {
    int m = matrix.size();  // length of rows
    int n = matrix[0].size(); 

    for (int j = 0; j < n; j++) // iterates for the columns
    {
        if (matrix[i][j] != 0) // marks the non zero elements of the column  
        {
            matrix[i][j] = -1; 
        }
    }
}

void markCol(vector<vector<int>> & matrix, int j) {
    int m = matrix.size();  // length of rows
    int n = matrix[0].size(); 

    for (int i = 0; i < m; i++) // iterates for the columns
    {
        if (matrix[i][j] != 0) // marks the non zero elements of the column  
        {
            matrix[i][j] = -1; 
        }
    }
}

void markElements(vector<vector<int>> & matrix) {
    int m = matrix.size();  // length of rows
    int n = matrix[0].size(); // length of columns

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(matrix[i][j] == 0 ){
                markRow(matrix, i); 
                markCol(matrix, j); 
            }
        }
        
    }
}

void setZeros(vector<vector<int>>& matrix) {
    int m = matrix.size(); 
    int n = matrix[0].size(); 

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(matrix[i][j] == -1) {
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
        markElements(matrix);
        setZeros(matrix);

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
