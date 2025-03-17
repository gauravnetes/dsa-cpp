#include<bits/stdc++.h>
using namespace std; 

void reverseString(char name[], int n) {
    int s = 0;
    int e = n - 1; 
    while (s < e)       
    {
        swap(name[s++], name[e--]); 
    }
}

int getLen(char name[]) {
    int count = 0; 
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++; 
    }
    return count; 
}
int main() {
    char name[20]; 
    cin >> name; 

    int len = getLen(name); 
    reverseString(name, len); 
    cout << name << endl; 

    return 0; 
}