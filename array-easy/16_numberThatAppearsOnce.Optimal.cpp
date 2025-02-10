#include <bits/stdc++.h>
using namespace std;

int findNumberThatAppearsOnce(vector<int> &arr, int n)
{   
    // we'll be using the xor as the xor of 2 same elements results 0
    // and xor or 0 ^ any element = that element
    int xorr = 0; 
    for (int i = 0; i < n; i++)
    {
        xorr ^= arr[i]; 
    }
    
    return xorr; 
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

        int numThatAppearsOnce = findNumberThatAppearsOnce(arr, n); 
        cout << numThatAppearsOnce << endl; 
    }

    return 0;
}
