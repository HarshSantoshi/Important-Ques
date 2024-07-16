#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll MOD = 1e9 + 7;

ll solve(int i, int k, vector<ll> &v, vector<vector<ll>> &dp)
{
    ll n = v.size();
    if (k < 0)
        return 0;
    if (k == 0)
    {
        return pow(2, n - i);
    }

    if (i == n)
        return 0;
    if (dp[i][k] != -1)
        return dp[i][k];

    ll ans = 0;
    ans += solve(i + 1, k, v, dp);//when i not taken
    ans %= MOD;
    ans += solve(i + 1, k - v[i], v, dp); // when i taken
    ans %= MOD;

    return dp[i][k] = ans;
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<ll>> dp(n + 2, vector<ll>(k + 5, -1));
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll res = solve(i + 1, k - v[i], v, dp);//aage ki combinations
        res *= pow(2, i);//peevhe ki combinations
        ans += res;
        ans %= MOD; 
      
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}