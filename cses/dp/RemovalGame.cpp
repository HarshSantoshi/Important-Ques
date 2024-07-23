// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

vector<vector<ll>> dp;
ll solve(int s, int e, vector<ll> &arr, int n)
{
    if (s > e)
        return 0;
    if (dp[s][e] != -1)
        return dp[s][e];
    ll start = arr[s] - solve(s + 1, e, arr, n);
    ll end = arr[e] - solve(s, e - 1, arr, n);
    return dp[s][e] = max(start, end);
}
int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n, 0);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    dp.resize(n + 1, vector<ll>(n + 1, -1));
    ll ans = solve(0, n - 1, arr, n);

    ll res = (ans + sum) / 2;
    cout << res << endl;

    return 0;
}

