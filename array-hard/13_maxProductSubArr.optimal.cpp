#include <bits/stdc++.h>
using namespace std;

int findMaxProductSubArr(vector<int> &arr, int n)
{       
    int prefix = 1, suffix = 1; 
    int maxi = INT_MIN; 
    for (int i = 0; i < n; i++)
    {
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1; 
        prefix *= arr[i]; 
        suffix *= arr[n - i - 1]; 
        maxi = max(maxi, max(prefix, suffix)); 
    }
    return maxi; 
}   

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int maxProductSum = findMaxProductSubArr(arr, n);
        cout << maxProductSum << endl;

    }
    return 0; 
}
