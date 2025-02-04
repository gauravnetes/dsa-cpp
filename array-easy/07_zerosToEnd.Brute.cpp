#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &arr, int n)
{
    vector<int> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }
    int nz = temp.size();

    for (int i = 0; i < nz; i++)
    {
        arr[i] = temp[i];
    }

    for (int i = nz; i < arr.size(); i++)
    {
        arr[i] = 0;
    }
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