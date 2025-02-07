#include <bits/stdc++.h>
using namespace std;

// if the array contains only positives and zeros
// for negative refer to the better solution

vector<int> findTwoSum(vector<int> &arr, int n, int target)
{   
    map<int, int> mpp; 
        for(int i = 0; i < n; i++) {
            int a = arr[i]; 
            int more = target - a; 
            if(mpp.find(more) != mpp.end()) {
                return {mpp[more], i}; 
            }
            mpp[a] = i; 
        }
    return {-1, -1}; 
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

        vector<int> twoSum = findTwoSum(arr, n, target); 
        cout << twoSum[0] << " " << twoSum[1] << endl; 
    }

    return 0;
}
