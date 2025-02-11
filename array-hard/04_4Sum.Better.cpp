#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findFourSum(vector<int> &arr, int n, int target)
{
    set<vector<int>> st; 
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) 
        {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = arr[i] + arr[j]; 
                sum += arr[k]; 
                long long fourth = target - sum; 
                if (hashset.find(fourth) != hashset.end() )
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], static_cast<int>(fourth)}; 
                    sort(temp.begin(),  temp.end()); 
                    st.insert(temp); 
                }
                hashset.insert(arr[k]); 
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end()); 
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

        vector<vector<int>> fourSum = findFourSum(arr, n, target);
        for (int i = 0; i < fourSum.size(); i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                cout << fourSum[i][j] << " "; 
            }
            cout << endl;
        } 
        if (fourSum.empty())
        {
            cout << "No Quarts"; 
        }
    }

    return 0;
}
