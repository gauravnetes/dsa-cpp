#include <bits/stdc++.h>
using namespace std;

int largest(vector<int> &arr, int n)
{
    // code here
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

int main()
{
    int t;
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

        int largestElement = largest(arr, n);

        cout << largestElement << endl;
    }
    return 0; 
}