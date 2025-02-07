#include <bits/stdc++.h>
using namespace std;

int findMaxSubArrSum(vector<int> &arr, int n)
{       
    int sum = 0, maxi = INT_MIN; 
    for (int i = 0; i < n; i++)
    {
        sum += arr[i]; 
        if (sum > maxi)
        {
            maxi = sum; 
        }
        if (sum < 0)
        {
            sum = 0; 
        }
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

        int maxSubArrSum = findMaxSubArrSum(arr, n);
        cout << maxSubArrSum << endl;

    }
    return 0;
}
