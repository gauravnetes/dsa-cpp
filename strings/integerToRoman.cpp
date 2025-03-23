#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; 
    string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; 
    string result = ""; 
    
    for (int i = 0; i < 13; i++) {
        while (num >= val[i]) {
            result += sym[i];
            num -= val[i];
        }
    }
    return result;
}

int main() {
    int num;
    cin >> num; 

    string romanNumeral = intToRoman(num);
    cout << romanNumeral << endl;

    return 0;
}
