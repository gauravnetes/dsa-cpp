#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findFourSumOptimal(vector<int> &arr, int n, int target)
{
    vector<vector<int>> ans; 
    sort(arr.begin(), arr.end()); 
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;
            int k = j + 1; 
            int l = n - 1; 
            while (k < l)
            {
                long long sum = arr[i]; 
                sum += arr[j]; 
                sum += arr[k]; 
                sum += arr[l]; 
                if (sum == target)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]}; 
                    ans.push_back(temp); 
                    k++; l--; 
                    while (k < l && arr[k] == arr[k -1]) k++; 
                    while (k < l && arr[l] == arr[l - 1]) l--; 
                    
                }
                else if (sum < target) k++; 
                else l--; 
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
        int target;  
        cin >> target; 

        vector<vector<int>> fourSumOptimal = findFourSumOptimal(arr, n, target);
        for (int i = 0; i < fourSumOptimal.size(); i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                cout << fourSumOptimal[i][j] << " "; 
            }
            cout << endl;
        } 
        if (fourSumOptimal.empty())
        {
            cout << "No Quarts"; 
        }
    }

    return 0;
}
