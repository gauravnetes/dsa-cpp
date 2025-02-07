
#include <bits/stdc++.h>
using namespace std;

vector<int> findNextPermutation(vector<int> &arr, int n)
{       
        int pivot = -1; 
        // finding pivot
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] < arr[i + 1]) {
                pivot = i; 
                break;
            }
        }
        // if array is in descending order (pivot = -1) reverse the whole
        if(pivot == -1) {
            reverse(arr.begin(), arr.end());
            return arr;
        }
        // find element just larger than pivot and swap
        for(int i = n -1; i > pivot; i--) {
            if(arr[i] > arr[pivot]) {
                swap(arr[pivot], arr[i]);
                break;
            }
        }
        // reverse the subarray after the pivot to get next permutation
        if (pivot + 1 < n) {
            reverse(arr.begin() + pivot + 1, arr.end());
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

        vector<int> nextPermutation =  findNextPermutation(arr, n);
        for (int i = 0; i < nextPermutation.size(); i++)
        {
            cout << nextPermutation[i] << " "; 
        }
        cout << endl; 
    }
    return 0;
}
