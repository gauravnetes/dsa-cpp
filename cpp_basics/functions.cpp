#include<bits/stdc++.h>
using namespace std; 

// void printName(string name) {
//     cout << "hey " << name << endl; 
// }
// int main() {
//     string name; 
//     getline(cin, name); 
//     printName(name); 
//     return 0; 
// }

int sum(int num1, int num2) {
    int num3 = num1 + num2; // 5 + 6
    return num3; // 11
}
int main() {
    int num1, num2; 
    cin >> num1 >> num2; 
    int res = sum(num1, num2); // res = 11 (num3 returned)
    cout << res; // 11
    return 0; 
}