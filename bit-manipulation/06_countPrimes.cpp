#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> countPrimes(int n) {
    vector<int> ans; 
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            ans.push_back(i); 
            while(n % i == 0) {
                n /= i; 
            }
        }
    }
    if(n != 1) ans.push_back(n); 
    sort(ans.begin(), ans.end());  
    return ans; 
}

int main() {
    int n;
    cin >> n;

    vector<int> result = countPrimes(n);
    for(int prime : result) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
