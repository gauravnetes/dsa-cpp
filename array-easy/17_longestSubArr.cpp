#include <bits/stdc++.h>
using namespace std;

// if the array contains only positives and zeros
// for negative refer to the better solution

int FindLongestSubArray(vector<int> &arr, int n, int k)
{   
    unordered_map<long long, int> prefixMap; 
    int prefixSum = 0, maxLen = 0; 
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];  // updating prefix sum

        // if prefixSum = k 
        if (prefixSum == k)
        {
            maxLen = i + 1; 
        }

        // if  prefixSum - k exists in map 
        if (prefixMap.find(prefixSum - k) != prefixMap.end())
        {
            maxLen = max(maxLen, i - prefixMap[prefixSum - k]); 
        }
        
        if (prefixMap.find(prefixSum) == prefixMap.end())
        {
            prefixMap[prefixSum] = i; 
        }
        
        
    }
    
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
        int k; 
        cin >> k; 

        int longestSubArr = FindLongestSubArray(arr, n, k); 
        cout << longestSubArr; 
    }

    return 0;
}
