#include <bits/stdc++.h>
using namespace std;

void doSomething(int arr[], int n) {
    arr[0] += 100; 
    cout << "value inside function: " << arr[0] << endl; // 440
}
int main()
{
    int n = 5; 
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    doSomething(arr, n); 
    cout << "value outside function: " << arr[0] << endl; // 440 cause always passed by reference
    return 0;
}