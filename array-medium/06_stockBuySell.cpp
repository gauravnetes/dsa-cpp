#include <bits/stdc++.h>
using namespace std;

int findBestDayToBuyAndSellStocks(vector<int> &arr, int n)
{       
    int mini = arr[0], profit = 0; 
    for(int i = 1; i < n; i++) {
        int cost = arr[i] - mini; 
        profit = max(profit, cost);
        mini = min(mini, arr[i]);  
    }
    return profit; 
}   

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int bestDayToBuyAndSellStocks = findBestDayToBuyAndSellStocks(arr, n);
        cout << bestDayToBuyAndSellStocks << endl;

    }
    return 0;
}
