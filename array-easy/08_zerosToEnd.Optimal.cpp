#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeroes(vector<int> &arr, int n)
{
    int j = -1; 
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            j = i; 
            break;
        }
    }
    if (j == -1)
    {
        return arr; 
    }
    

    for (int i = j + 1; i < n; i++)
    {
        if(arr[i] != 0) {
            int temp = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = temp; 
            j++;
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

        moveZeroes(arr, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}