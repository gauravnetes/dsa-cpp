#include <bits/stdc++.h>
using namespace std;

// For the 1st type of problem it can be done without the map data structure.
int findTwoSum(vector<int> &arr, int n, int target)
{   
    int left = 0, right = n - 1; 
    sort(arr.begin(), arr.end()); 
    while (left < right)
    {
        int sum = arr[left] + arr[right]; 
        if(sum == target) return true; 
        else if(sum < target) left++; 
        else if(sum > target) right--; 
    }
    return false;
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

        int twoSum = findTwoSum(arr, n, target); 
        cout << twoSum << endl; 
    }

    return 0;
}
