#include <iostream>
#include <climits>
using namespace std;

int divide(int dividend, int divisor) {
    if(dividend == divisor) return 1; 
    bool sign = true; 
    if(dividend >= 0 && divisor < 0) sign = false; 
    if(divisor >= 0 && dividend < 0) sign = false; 
    
    long long n = abs((long long) dividend); 
    long long d = abs((long long) divisor);
    long long ans = 0; 
    
    while(n >= d) {
        int cnt = 0; 
        while(n >= (d << (cnt + 1))) {
            cnt++; 
        }
        ans += (1LL << cnt); 
        n = n - (d << cnt); 
    }
    
    if(ans >= (1LL << 31)) 
        return sign ? INT_MAX : INT_MIN; 

    return sign ? (int)ans : (int)-ans; 
}

int main() {
    int dividend, divisor;
    cin >> dividend >> divisor;
    cout << divide(dividend, divisor) << endl;
    return 0;
}
