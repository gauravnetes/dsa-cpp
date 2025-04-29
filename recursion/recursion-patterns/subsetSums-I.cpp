#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public: 
    void findSubsetSum(int index, int sum, vector<int> &arr, vector<int> &subsetSum) {
        if(index == arr.size()) {
            subsetSum.push_back(sum); 
            return; 
        }
        
        findSubsetSum(index + 1, sum + arr[index], arr, subsetSum); // pick
        findSubsetSum(index + 1, sum, arr, subsetSum); // not pick
    }
    
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> subsetSum; 
        findSubsetSum(0, 0, arr, subsetSum); 
        sort(subsetSum.begin(), subsetSum.end()); 
        return subsetSum; 
    }
};

int main() {
    int n;
    cin >> n; // input size of array
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i]; // input array elements
    }
    
    Solution solution;
    vector<int> result = solution.subsetSums(arr);
    
    // Output the results
    for(int sum : result) {
        cout << sum << " "; // output each subset sum
    }
    
    return 0;
}
