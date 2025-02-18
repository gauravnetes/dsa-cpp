
#include <bits/stdc++.h>
using namespace std;

vector<int> findrepeatingAndMissingElement(vector<int> &arr, int n)
{       
    // S - Sn
    // S2 - Sn2
    long long Sn = (n * (n + 1)) / 2; 
    long long Sn2 = (n * (n + 1) * (2 * n + 1)) / 6;
    long long s = 0; 
    long long s2 = 0; 
    for (int i = 0; i < n; i++)
    {
        s += arr[i]; 
        s2 += (long long)arr[i] * (long long)arr[i]; 
    }
    long long val1 = s - Sn; // x - y
    long long val2 = s2 - Sn2; 
    val2 = val2 / val1; 
    long long x = (val1 + val2) / 2; 
    long long y = x - val1; 

    return {(int)x, (int)y};
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
