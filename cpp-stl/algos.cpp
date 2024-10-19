#include<bits/stdc++.h>
using namespace std; 

int main() {
    sort(a, a+n);
    sort(v.begin(), v.end()); 

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}}; 
    // sort according the second element
    // if second element is same then
    // sort acc to first element but in descending order

    // output: {{4, 1}, {2, 1}, {1, ,2}}
    sort(a, a+n, comp);

    string s = "123"; 
    sort(s.begin(), s.end())
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    
    // max element:
    int maxi = *max_element(a, a+n); 
    
}