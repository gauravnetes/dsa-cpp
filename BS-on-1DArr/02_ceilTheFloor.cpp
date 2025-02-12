#include <bits/stdc++.h>
using namespace std; 


vector<int> getFloorAndCeil(vector<int> &arr, int n, int x) {
    // code here
    sort(arr.begin(), arr.end()); 
    vector<int> result; 
    int low = 0, high = n - 1; 
    int floorVal = -1, ceilVal = -1; 
    int ans = -1; 
    while(low <= high) {
        int mid = (low + high) / 2; 
        if(arr[mid] <= x) {
            floorVal = arr[mid]; 
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    
    low = 0, high = n - 1; 
    while(low <= high) {
        int mid = (low + high) / 2; 
        if(arr[mid] >= x) {
            ceilVal = arr[mid]; 
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }
    
    result = {floorVal, ceilVal}; 
    return result; 
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

        int x; 
        cin >> x; 

        vector<int> ceilTheFloor = getFloorAndCeil(arr, n, x);
        for (int i = 0; i < ceilTheFloor.size(); i++)
        {
            cout << ceilTheFloor[i] << " "; 
        }
        
        cout << endl; 
    }
    return 0;
}
