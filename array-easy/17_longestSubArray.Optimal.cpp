#include <bits/stdc++.h>
using namespace std;

// if the array contains only positives and zeros
// for negative refer to the better solution

int FindLongestSubArray(vector<int> &arr, int n, int k)
{   
    int left = 0, right = 0; 
    long long sum = arr[0]; 
    int maxLen = 0; 

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left]; 
            left++; 
        }
        if (sum == k)   
        {
            maxLen = max(maxLen, right - left + 1); 
        }
        right++; 
        if(right < n) sum += arr[right];
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
