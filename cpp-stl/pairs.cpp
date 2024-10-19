#include<bits/stdc++.h>
using namespace std;

int main() {
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second;     
    
    cout << endl; 

    pair<int, pair<int, int>> pa = {1, {3, 5}}; 
    cout << p.first << " " << pa.second.second << " " << pa.second.first; 

    cout << endl; 

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}}; 
    cout << arr[0].second; // 2
}