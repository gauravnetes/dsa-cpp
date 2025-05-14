#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0; 
        int n = height.size(); 
        if(n == 0) return 0; 

        vector<int> prefixMax(n); 
        vector<int> suffixMax(n); 

        prefixMax[0] = height[0]; 
        for(int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);  
        }

        suffixMax[n - 1] = height[n - 1]; 
        for(int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]); 
        }

        for(int i = 0; i < n; i++) {
            int leftMax = prefixMax[i]; 
            int rightMax = suffixMax[i]; 
            if(height[i] < leftMax && height[i] < rightMax) {
                int water = min(leftMax, rightMax) - height[i]; 
                total += water;
            }
        }
        return total; 
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> height(n);
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution sol;
    cout << sol.trap(height) << endl;

    return 0;
}
