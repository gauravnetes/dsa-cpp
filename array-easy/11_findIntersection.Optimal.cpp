#include <bits/stdc++.h>
using namespace std;

vector<int> findIntersect(vector<int> &a, vector<int> &b, int s1, int s2)
{
    // Your code here
    // return vector with correct order of elements
    int i = 0; 
    int j = 0; 
    vector<int> result; 
    while (i < s1 && j < s2)
    {
        if (a[i] < b[j]) i++; 
        else if (a[i] > b[j]) j++; 
        else {
            result.push_back(a[i]); 
            i++; 
            j++; 
        }
    }
    return result;    
}

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        int s1, s2;
        cin >> s1;
        cin >> s2; 

        vector<int> arr1(s1);
        for (int i = 0; i < s1; i++)
        {
            cin >> arr1[i];
        }
        vector<int> arr2(s2);
        for (int i = 0; i < s2; i++)
        {
            cin >> arr2[i];
        }
        vector<int> interSectArr = findIntersect(arr1, arr2, s1, s2);
        for (int i = 0; i < interSectArr.size(); i++)
        {
            cout << interSectArr[i] << " "; 
        }
        cout << endl; 
    }

    return 0;
}