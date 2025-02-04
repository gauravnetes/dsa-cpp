#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b, int s1, int s2)
{
    // Your code here
    // return vector with correct order of elements
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> unionArr;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while (j < n2)
    {
        if (unionArr.size() == 0 || unionArr.back() != b[j])
        {
            unionArr.push_back(b[j]);
        }
        j++;
    }
    while (i < n1)
    {
        if (unionArr.size() == 0 || unionArr.back() != a[i])
        {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    return unionArr;
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
        vector<int> unionArr = findUnion(arr1, arr2, s1, s2);
        for (int i = 0; i < unionArr.size(); i++)
        {
            cout << unionArr[i] << " "; 
        }
        cout << endl; 
    }

    return 0;
}