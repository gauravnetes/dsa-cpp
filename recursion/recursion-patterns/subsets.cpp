#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; 
        vector<int> subset; 
        createSubset(nums, 0, res, subset); 
        return res; 
    }

    void createSubset(vector<int> &nums, int index, vector<vector<int>> &res, vector<int> &subset) {
        if(index == nums.size()) {
            res.push_back(subset); 
            return; 
        }

        subset.push_back(nums[index]); 
        createSubset(nums, index + 1, res, subset); 

        subset.pop_back(); 
        createSubset(nums, index + 1, res, subset); 
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    vector<vector<int>> result = sol.subsets(nums);

    for (const auto& subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
