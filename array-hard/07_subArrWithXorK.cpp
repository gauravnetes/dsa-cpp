#include <bits/stdc++.h>
using namespace std;

int findSubArrWithXorK(vector<int> &arr, int n)
{       
    
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

        int subArrWithXorK = findSubArrWithXorK(arr, n);
        cout << subArrWithXorK << endl;

    }
    return 0;
}
