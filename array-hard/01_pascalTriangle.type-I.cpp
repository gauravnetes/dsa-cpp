#include <bits/stdc++.h>
using namespace std;
// generating each row: (type - 2)
vector<int> generateRow(int row) {
    long long ans = 1; 
    vector<int> ansRow; 
    ansRow.push_back(1); 
    for (int col = 1; i < row; col++)
    {
        ans = ans * (row - col); 
        ans = ans / col; 
        ansRow.push(ans); 
    }
     return ansRow; 
}
vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> ans; 
    for (int i = 1; i < n; i++)
    {
        vector<int> temp = generateRow(i); 
        ans.push_back(temp); 
    }
    return ans; 
}

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> triangle = pascalTriangle(n); 

        for(const auto &row : triangle) {
            for(int num : row) {
                cout << num << " "; 
            }
            cout << endl; 
        }
    }

    return 0;
}
