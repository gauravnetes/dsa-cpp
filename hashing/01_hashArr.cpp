#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n; 

    int arr[n]; 
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; 
    }
    // precompute
    int hashArr[13] = {0}; // declare the hash arr size according to the max element of the Array. 
    //  as here the max element of the arr is 12 so we declare the hasharr
    //  to 13
    for (int i = 0; i < n; i++)
    {
        hashArr[arr[i]] += 1; 
    }
    

    int q; 
    cin >> q;
    while (q--)
    {
        int num; 
        cin >> num;
        // fetch
        cout << hashArr[num]  << endl;
    }
    return 0; 
}