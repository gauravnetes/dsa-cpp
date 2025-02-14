#include <bits/stdc++.h>
using namespace std;

int findLongestSubArrSum0(vector<int> &arr, int n)
{       
    unordered_map<int, int> mpp; 
        int maxi = 0, sum = 0; 
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i]; 
            if(sum == 0) {
                maxi = i + 1;
            } else {
                if(mpp.find(sum) != mpp.end()) {
                    maxi = max(maxi, i - mpp[sum]); 
                } else {
                    mpp[sum] = i; 
                }
            }
        }
        return maxi;  
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

        int longestSubbArrSum0 = findLongestSubArrSum0(arr, n);
        cout << longestSubbArrSum0 << endl;

    }
    return 0;
}
