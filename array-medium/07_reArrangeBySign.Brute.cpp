#include <bits/stdc++.h>
using namespace std;

vector<int> reArrangeArrBySign(vector<int> &arr, int n)
{       
    vector<int> positiveArr; 
    vector<int> negArr; 
    vector<int> finalArr; 

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            negArr.push_back(arr[i]); 
        }
        else {
            positiveArr.push_back(arr[i]); 
        }
    }

    int posIndex = 0, negIndex = 0; 
    while (posIndex < positiveArr.size() && negIndex < negArr.size())
    {
        finalArr.push_back(positiveArr[posIndex]);
        posIndex++; 
        finalArr.push_back(negArr[negIndex]);
        negIndex++;   
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
