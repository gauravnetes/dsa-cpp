#include <iostream>
using namespace std;

int minBitFlips(int start, int goal) {
    int ans = start ^ goal; 
    int cnt = 0; 
    while (ans) {
        ans &= (ans - 1); // Turn off the rightmost set bit
        cnt++;
    }
    return cnt;
}

int main() {
    int start, goal;
    cin >> start >> goal;
    cout << minBitFlips(start, goal) << endl;
    return 0;
}
