#include <bits/stdc++.h>
using namespace std;

vector<int> reArrangeArrBySign(vector<int> &arr, int n)
{       
    vector<int> finalArr(n); 
    int posIndex = 0, negIndex = 1; 
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            finalArr[posIndex] = arr[i]; 
            posIndex += 2; 
        }else {
            finalArr[negIndex] = arr[i]; 
            negIndex += 2; 
        }
    }
    return finalArr; 
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

        vector<int> reArrangedArr =  reArrangeArrBySign(arr, n);
        for (int i = 0; i < reArrangedArr.size(); i++)
        {
            cout << reArrangedArr[i] << " "; 
        }
        cout << endl; 
    }
    return 0;
}
