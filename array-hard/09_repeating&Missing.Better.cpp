
#include <bits/stdc++.h>
using namespace std;

vector<int> findrepeatingAndMissingElement(vector<int> &arr, int n)
{       
    int hash[n + 1] = {0}; 
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++; 
    }
    int repeating = -1, missing = -1; 
    for (int i = 1; i <= n; i++)
    {
        if(hash[i] == 2) repeating = i; 
        else if(hash[i] == 0) missing = i; 

        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }
    return {repeating, missing};
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

        vector<int> repeatingAndMissingElement =  findrepeatingAndMissingElement(arr, n);
        for (int i = 0; i < repeatingAndMissingElement.size(); i++)
        {
            cout << repeatingAndMissingElement[i] << " "; 
        }
        cout << endl; 
    }
    return 0;
}
