#include<bits/stdc++.h>
#include <iostream>
using namespace std; 

int main() {
    int x = 0; 
    int t; 
    cin >> t;
    string s; 
    while (t)
    {
        cin >> s; 
        if (s == "++X" || s == "X++") {
            x++; 
        } else if(s == "--X" || s == "--X") {
            x--;
        }
        t--; 
    }
    cout << x;
    return 0; 
}