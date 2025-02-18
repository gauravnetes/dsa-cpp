#include <bits/stdc++.h>
using namespace std;

// int inversionCount = 0; // in Interview avoid keeping global variables
// merge 
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    int cnt = 0; 
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        // right is smaller
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); 
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return cnt; 
}

// merge sort
int mS(vector<int> &arr, int low, int high)
{
    int cnt = 0; 
    if (low >= high) return cnt;
    int mid = (low + high) / 2;
    cnt += mS(arr, low, mid);
    cnt += mS(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);
    return cnt; 
}

int findCountofInversions(vector<int> &arr, int n)
{       
    return mS(arr, 0, n - 1); 
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

        int countOfInversions = findCountofInversions(arr, n);
        cout << countOfInversions << endl;

    }
    return 0;
}
