#include <bits/stdc++.h>
using namespace std; 


// pass by value
void doSomething(int num) {
    cout << num << endl;
    num += 5; 
    cout << num << endl;
    num += 5; 
    cout << num << endl;
}
int main() {
    int num = 10;
    doSomething(num); // the num passes by a copy. the original num doesn't go to the function
    cout << num << endl; // so the original value of num is 10 again 
    return 0; 
}