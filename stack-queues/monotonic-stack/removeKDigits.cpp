#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    stack<char> st;
    for (char& ch : num) {
        while (!st.empty() && k > 0 && st.top() > ch) {
            st.pop();
            k--;
        }
        st.push(ch);
    }

    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());

    int i = 0;
    while (i < res.size() && res[i] == '0') i++;
    res = res.substr(i);

    return res.empty() ? "0" : res;
}

int main() {
    string num;
    int k;
    cin >> num >> k;
    cout << removeKdigits(num, k) << endl;
    return 0;
}
