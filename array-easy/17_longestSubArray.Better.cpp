#include <bits/stdc++.h>
using namespace std;

// if the array contains only positives and zeros
// for negative refer to the better solution

int FindLongestSubArray(vector<int> &arr, int n, int k)
{   
    map<long long, int> preSumMap; 
        long long sum = 0; 
        int maxLen = 0; 
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i]; 
            if(sum == k) {
                maxLen = max(maxLen, i+1);  
            }
            int rem = sum - k; 
            if(preSumMap.find(rem) != preSumMap.end()) {
                int len = i - preSumMap[rem]; 
                maxLen = max(maxLen, len); 
            }
            preSumMap[sum] = i; 
        }
        return maxLen; 
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
