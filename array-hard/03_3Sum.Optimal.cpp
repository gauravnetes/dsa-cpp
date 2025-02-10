#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findThreeSum(vector<int> &arr, int n)
{
    vector<vector<int>> ans; 
        sort(arr.begin(), arr.end()); 
        for(int i = 0; i < arr.size(); i++) {
            if(i > 0 && arr[i] == arr[i - 1]) continue; 
            int j = i + 1; 
            int k = arr.size() - 1; 
            while(j < k) {
                int sum = arr[i] + arr[j] + arr[k]; 
                if(sum > 0) {
                    k--; 
                } else if (sum < 0) {
                    j++; 
                } else {
                    vector<int> temp = {arr[i], arr[j], arr[k]}; 
                    ans.push_back(temp); 
                    j++; 
                    k--; 
                    while(j < k && arr[j] == arr[j - 1]) j++; 
                    while(j < k && arr[k] == arr[k + 1]) k--; 
                }
            }
        }
        return ans; 
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

        vector<vector<int>> threeSum = findThreeSum(arr, n);
        for (int i = 0; i < threeSum.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << threeSum[i][j] << " "; 
            }
            cout << endl;
        } 
        if (threeSum.empty())
        {
            cout << "No Triplets"; 
        }
    }

    return 0;
}
