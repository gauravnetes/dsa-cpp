#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> findPSE(const vector<int>& heights) {
    int n = heights.size();
    vector<int> psE(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        psE[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psE;
}

vector<int> findNSE(const vector<int>& heights) {
    int n = heights.size();
    vector<int> nsE(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        nsE[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nsE;
}

int largestRectangleArea(const vector<int>& heights) {
    int n = heights.size();
    vector<int> pse = findPSE(heights);
    vector<int> nse = findNSE(heights);
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = nse[i] - pse[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    cout << largestRectangleArea(heights) << endl;
    return 0;
}
