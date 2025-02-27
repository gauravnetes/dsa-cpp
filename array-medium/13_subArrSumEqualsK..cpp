#include <bits/stdc++.h>
using namespace std;

int findSubArrSumEqualsK(vector<int> &arr, int n, int k)
{       
    map<int, int> mpp; 
    int preSum = 0, cnt = 0; 
    mpp[0] = 1; 
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i]; 
        int remove = preSum - k; 
        cnt += mpp[remove]; 
        mpp[preSum] += 1; 
    }
    return cnt; 
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
        int k; 
        cin >> k; 

        int subArrSumCount = findSubArrSumEqualsK(arr, n, k);
        cout << subArrSumCount << endl;

    }
    return 0;
}
