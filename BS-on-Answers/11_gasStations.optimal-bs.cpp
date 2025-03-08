#include <bits/stdc++.h>
using namespace std;

int numberOfGasStationsRequired(long double dist, vector<int> &stations)
{
    int cnt = 0;
    for (int i = 1; i < stations.size(); i++)
    {
        int numberInBetween = ((stations[i] - stations[i - 1]) / dist);
        if ((stations[i] - stations[i - 1]) / dist == numberInBetween + dist)
        {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

double minimizeMaxDistance(vector<int> &stations, int n, int k)
{

    long double low = 0;
    long double high = 0;
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(stations[i + 1], stations[i]));
    }
    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = (low + high) / 2.0;
        int cnt = numberOfGasStationsRequired(mid, stations);
        if (cnt > k)
            low = mid;
        else
            high = mid;
    }
    return (high * 100) / 100;
}

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> stations(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stations[i];
        }

        double minDistance = minimizeMaxDistance(stations, n, k);
        cout << fixed << setprecision(2) << minDistance << endl;
    }
    return 0;
}