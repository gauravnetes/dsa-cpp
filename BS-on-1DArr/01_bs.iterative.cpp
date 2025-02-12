#include <bits/stdc++.h>
using namespace std;

int findTargetByBS(vector<int> &arr, int n, int target)
{       
    int low = 0, high = n - 1; 
    while (low <= high )
    {
        int mid = (low + high) / 2; 
        if(arr[mid] == target) return mid; 
        else if(target > arr[mid]) low = mid + 1; 
        else high = mid - 1; 
    }
    return -1; 
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

        int target; 
        cin >> target; 

        int targetByBS = findTargetByBS(arr, n, target);
        cout << targetByBS << endl;

    }
    return 0;
}
