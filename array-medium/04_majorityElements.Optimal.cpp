#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(vector<int> &arr, int n)
{       
    int count = 0; 
        int el; 
        for(int i = 0; i < arr.size(); i++) {
            if(count == 0) {
                count = 1; 
                el = arr[i];  
            } else if(arr[i] == el) {
                count++; 
            } else {
                count--; 
            }
        }
        int count1 = 0; 
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == el) {
                count1++; 
            }
        }
        if(count1 > (arr.size() / 2)) { return el; } 
        return - 1; 
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

        int majorityElement = findMajorityElement(arr, n);
        cout << majorityElement << endl;

    }
    return 0;
}
