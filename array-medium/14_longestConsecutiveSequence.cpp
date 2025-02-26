#include <bits/stdc++.h>
using namespace std;

int findLongestConsecutiveSequence(vector<int> &arr, int n)
{       
    unordered_set<int> st; 
    int longest = INT_MIN; 
    if(n == 0) return 0; 
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]); 
    }

    // iterate through the set: 
    for(auto it : st) {
        if(st.find(it - 1) == st.end()) {
            int cnt = 1; 
            int x = it; 
            while (st.find(x + 1) != st.end())
            {
                cnt += 1; 
                x = x + 1; 
            }
            longest = max(cnt, longest); 
        }
    }
    return longest; 
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

        int loongestConsecutiveSequence = findLongestConsecutiveSequence(arr, n);
        cout << loongestConsecutiveSequence << endl;

    }
    return 0;
}
