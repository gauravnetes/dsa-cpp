#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int n, int num) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == num) {
            return i; 
        }
    }
    return -1; 
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
        int num; 
        cin >> num; 
        int resultIndex = linearSearch(arr, n, num);
        cout << resultIndex << endl; 
    }

    return 0;
}