#include <bits/stdc++.h>
using namespace std;

int findMaxNumbersOfOnes(vector<int> &arr, int n)
{       
    int maxi = 0, count = 0; 
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++; 
            maxi = max(maxi, count);
        } 
        else {
            count = 0; 
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

        int maxNumbersOfOnes = findMaxNumbersOfOnes(arr, n);
        cout << maxNumbersOfOnes << endl;

    }
    return 0;
}
