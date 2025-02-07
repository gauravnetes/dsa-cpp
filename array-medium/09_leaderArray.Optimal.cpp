
#include <bits/stdc++.h>
using namespace std;

vector<int> findArrLeader(vector<int> &arr, int n)
{       
        vector<int> leaderArr;

        // right most element is always a leader
        int maxRight = arr[n - 1]; 
        leaderArr.push_back(maxRight); 
        
        for(int i = n-2; i >= 0; i--) {
            if(arr[i] >= maxRight) {
                maxRight = arr[i];
                leaderArr.push_back(arr[i]);
            }
        }
        reverse(leaderArr.begin(), leaderArr.end());
        return leaderArr;
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

        vector<int> leaderArray =  findArrLeader(arr, n);
        for (int i = 0; i < leaderArray.size(); i++)
        {
            cout << leaderArray[i] << " "; 
        }
        cout << endl; 
    }
    return 0;
}
