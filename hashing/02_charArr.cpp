#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; 
    cin >> s; 

    // for only lowercase chars, hash array size can be declared 26
    // if the string includes upper and lower both then hash arr size 
    // can be declared 256

    // pre compute
    int hash[256] = {0}; 
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;
    }
    
    int q; 
    cin >> q; 

    while (q--)
    {
        char c; 
        cin >> c; 
        // fetch
        cout << hash[c] << endl; 
    }
    return 0; 
    
}