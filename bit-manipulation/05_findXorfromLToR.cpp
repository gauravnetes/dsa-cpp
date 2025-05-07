#include <iostream>
using namespace std;

int func(int n) {
    if(n % 4 == 1) return 1; 
    else if(n % 4 == 2) return n + 1; 
    else if(n % 4 == 3) return 0; 
    else return n; 
}

int findXOR(int L, int R) {
    return func(L - 1) ^ func(R); 
}

int main() {
    int L, R;
    cin >> L >> R;
    cout << findXOR(L, R) << endl;
    return 0;
}
