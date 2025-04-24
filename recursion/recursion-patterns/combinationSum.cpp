#include <iostream>
#include <vector>
using namespace std;

void findCombination(int index, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
    if (index == arr.size()) {
        if (target == 0) {
            ans.push_back(ds);
        }
        return;
    }

    if (arr[index] <= target) {
        ds.push_back(arr[index]);
        findCombination(index, target - arr[index], arr, ans, ds);
        ds.pop_back();
    }

    findCombination(index + 1, target, arr, ans, ds);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}

int main() {
    int n, target;
    cin >> n;

    vector<int> candidates(n);
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i];
    }

    cin >> target;

    vector<vector<int>> result = combinationSum(candidates, target);

    for (const auto& comb : result) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
