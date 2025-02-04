#include <bits/stdc++.h>
using namespace std;

int checkIfSorted(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true; 
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

        int ifSorted = checkIfSorted(arr, n);

        cout << ifSorted << endl;
    }

    return 0;
}