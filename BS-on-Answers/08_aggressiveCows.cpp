#include <bits/stdc++.h>
using namespace std;
bool canWePlace(vector<int> arr, int distance, int cows) {
    int cntCows = 1; 
    int lastCow = arr[0]; 
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] - lastCow >= distance)
        {
            cntCows++; 
            lastCow = arr[i]; 
        }
        if(cntCows >= cows) return true; 
    }
    return false;
}
int aggressiveCows(vector<int> &arr, int n, int N, int C)
{       
    sort(arr.begin(), arr.end()); 
    int low = 1; 
    int high = arr[N-1] - arr[0]; 
    while (low <= high)
    {
        int mid = (low + high) / 2; 
        if(canWePlace(arr, mid, C)) {
            low = mid + 1; 
        } else high = mid - 1; 
    }
    return high; 
}   

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        int n; 
        cin >> n; 
        int N, C;
        cin >> N >> C;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            cout << endl; 
        }

        int minDistance = aggressiveCows(arr, n, N, C);
        cout << minDistance << endl;

    }
    return 0;
}
