#include <bits/stdc++.h>
using namespace std;

vector<int> rightRotateByDOptimal(vector<int> &arr, int n, int d)
{
    d = d % n; 
    reverse(arr.begin(), arr.end() - d); 
    reverse(arr.end() - d, arr.end()); 
    reverse(arr.begin(), arr.end()); 

    return arr; 
}

// Manual Reverse function
// vector<int> Reverse(vector<int> &arr, int start, int end) {
//     while (start <= end)
//     {
//         int temp = arr[start];
//         arr[start] = arr[end]; 
//         arr[end] = temp; 
//         start++; 
//         end--; 
//     }
//     return arr; 
// }

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
        int d; 
        cin >> d; 

        rightRotateByDOptimal(arr, n, d);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " "; 
        }
        cout << endl; 
    }

    return 0;
}
