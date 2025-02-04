#include <bits/stdc++.h>
using namespace std;

vector<int> leftRotateByD(vector<int> &arr, int n, int d)
{
    d = d % n; 
    int temp[d]; 
    // placing the no. of elements to be rotated in the temp array 
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i]; 
    }
    // left shifting the elements in the main array.
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i]; 
    }
    // putting the elements back from the temp array to the main array
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];
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
        int d; 
        cin >> d; 

        leftRotateByD(arr, n, d);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " "; 
        }
        cout << endl; 
    }

    return 0;
}
