#include <bits/stdc++.h>
using namespace std;

int findMissingNumber(vector<int> &arr, int n)
{
    int xor1 = 0, xor2 = 0; 
    for (int i = 1; i < n; i++)
    {
        xor1 = xor1 ^ i; 
    }
    for (int i = 0; i < n - 1; i++)
    {
        xor2 = xor2 ^ arr[i]; 
    }
    
    return xor1 ^ xor2; 
}

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n - 1);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int missingNum = findMissingNumber(arr, n); 
        cout << missingNum; 
    }

    return 0;
}
