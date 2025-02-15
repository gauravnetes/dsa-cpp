#include <bits/stdc++.h>
using namespace std;

void findMergeSortedArr(vector<int> &arr1, int m,  vector<int> &arr2, int n)
{       
    // i = m - 1 => last valid index of nums1
    // j = n - 1 => last element in nums2
    // k = m + n - 1 => last index in nums1
    int i = m - 1; 
    int j = n - 1; 
    int k = m + n - 1; 
    
    // merge from the end
    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
        {
            arr1[k] = arr1[i]; 
            i--; 
        } else {
            arr1[k] = arr2[j]; 
            j--; 
        }
        k--; 
    }
    
}   

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        int m;
        cin >> m;
        int n;
        cin >> n;

        vector<int> arr1(m + n);
        for (int i = 0; i < m; i++)
        {
            cin >> arr1[i];
        }

        vector<int> arr2(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }

        findMergeSortedArr(arr1, m, arr2, n);
        for(int num : arr1) {
            cout << num << " "; 
        }
        cout << endl; 
    }
    return 0;
}
