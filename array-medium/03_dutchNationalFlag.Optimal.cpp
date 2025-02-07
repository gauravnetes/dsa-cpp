#include <bits/stdc++.h>
using namespace std;

// For the 1st type of problem it can be done without the map data structure.
vector<int> findModifiedArr(vector<int> &arr, int n)
{       
    int mid = 0, low = 0, high = n - 1; 
    while (mid <= high)
    {
        if (arr[mid] == 0) {
            swap(arr[mid], arr[low]); 
            mid++; 
            low++;
        } else if (arr[mid] == 1) {
            mid++; 
        } else {
            swap(arr[mid], arr[high]); 
            high--; 
        }
    }
    return arr; 
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

        vector<int> modifiedArr = findModifiedArr(arr, n); 
        for (int i = 0; i < modifiedArr.size(); i++)
        {
            cout << modifiedArr[i] << " "; 
        }
        cout << endl; 
    }

    return 0;
}
