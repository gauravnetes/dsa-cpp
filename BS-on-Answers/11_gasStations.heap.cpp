#include <bits/stdc++.h>
using namespace std;

double minimizeMaxDistance(vector<int>& stations, int n, int k) {
    vector<int> howMany(n - 1, 0); 
    priority_queue<pair<long double, int>> pq; 
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({stations[i+1] - stations[i], i}); 
    }
    
    for (int gasStations = 1; gasStations < n; gasStations++)
    {
        auto tp = pq.top(); pq.pop(); 
        int secInd = tp.second; 
        howMany[secInd]++; 
        long double initDiff = stations[secInd + 1] - stations[secInd]; 
        long double newSecLen = initDiff / (long double) (howMany[secInd] + 1); 
        pq.push({newSecLen, secInd}); 
    }
    return pq.top().first; 
}

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }

        double minDistance = minimizeMaxDistance(stations, n, k);
        cout << fixed << setprecision(2) << minDistance << endl;
    }
    return 0;
}