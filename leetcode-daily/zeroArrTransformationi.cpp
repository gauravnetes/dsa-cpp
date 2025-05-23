#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(); 
        vector<int> diff(n + 1, 0); 
        for(auto &q : queries) {
            int l = q[0]; int r = q[1]; 
            diff[l] -= 1; 
            if(r + 1 < n) 
                diff[r + 1] += 1; 
        }

        int prefixSum = 0; 
        for(int i = 0; i < n; i++) {
            prefixSum += diff[i]; 
            nums[i] += prefixSum;
            if(nums[i] > 0) return false;  
        }
        return true;  
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    vector<vector<int>> queries(q, vector<int>(2));
    for(int i = 0; i < q; ++i)
        cin >> queries[i][0] >> queries[i][1];

    Solution sol;
    cout << sol.isZeroArray(nums, queries) << endl;

    return 0;
}
