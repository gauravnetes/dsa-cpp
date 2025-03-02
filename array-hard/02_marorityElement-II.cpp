#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(vector<int> &arr, int n)
{       
    int count1 = 0, count2 = 0, el1 = INT_MIN, el2 = INT_MIN; 
        for(int i = 0; i < arr.size(); i++) {
            if(count1 == 0 && arr[i] != el2) {
                count1 = 1; 
                el1 = arr[i]; 
            } else if(count2 == 0 && arr[i] != el1) {
                count2 = 1; 
                el2 = arr[i]; 
            } else if(el1 == arr[i]) count1++; 
            else if(el2 == arr[i]) count2++; 
            else {
                count1--; 
                count2--; 
            }
        }
        vector<int> ls; 
        count1 = 0, count2 = 0; 
        for(int i = 0; i < arr.size(); i++) {
            if(el1 == arr[i]) count1++; 
            if(el2 == arr[i]) count2++; 
        }
        int mini = (int)(arr.size() / 3) + 1; 
        if(count1 >= mini) ls.push_back(el1); 
        if(count2 >= mini) ls.push_back(el2); 
        return ls; 
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
