#include <bits/stdc++.h>
using namespace std; 

void doSomething(int &num){    // &num stores the address of the variable hence take the original value
    cout << num << endl; 
    num += 10; 
    cout << num << endl; 
    num += 10; 
    cout << num << endl; 
}
int main() {
    int num = 10; 
    doSomething(num); 
    cout << num << endl; // it'll print 30. the modified value in the function as passed by the reference
    return 0; 
}