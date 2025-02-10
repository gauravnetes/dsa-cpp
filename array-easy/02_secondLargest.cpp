#include<bits/stdc++.h>
using namespace std; 


int getSecondLargest(vector<int> &arr, int n)
{
    // Code Here
    if (n < 2)
    {
        return -1;
    }
    int largest = arr[0];
    int sLargest = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            sLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > largest && arr[i] > sLargest)
        {
            sLargest = arr[i];
        }
    }
    return sLargest;
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

        int secondLargest = getSecondLargest(arr, n);

        cout << secondLargest << endl;
    }

    return 0;
}