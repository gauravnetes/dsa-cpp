#include <bits/stdc++.h>
using namespace std;

int findMissingNumber(vector<int> &arr, int n)
{
        int sum = (n * (n + 1)) / 2; 
        int s2 = 0; 
        for(int i = 0; i < arr.size(); i++) {
            s2 += arr[i]; 
        }
        return sum - s2; 
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
