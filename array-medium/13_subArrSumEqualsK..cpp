#include <bits/stdc++.h>
using namespace std;

int findSubArrSumEqualsK(vector<int> &arr, int n, int k)
{       
    map<int, int> mpp;
        mpp[0] = 1; 
        int prefixSum = 0, count = 0; 
        
        for(int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i]; 
            int remove = prefixSum - k; 
            count += mpp[remove]; 
            mpp[prefixSum] += 1; 
        }
        return count;
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
