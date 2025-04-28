

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

void solve()
{
    // By Farhadul Islam
    // Only Brute Force Bhai
    ll n;
    cin >> n;
    vector<ll> a(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    ll sz = n - 1;

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 1e9));
    for (int i = 1; i <= n; i += 1)
    {
        dp[i][i] = 0;
    }

    for (int l = 2; l <= n; l += 1)
    {

        for (int i = 1; i <= n - l + 1; i += 1)
        {

            ll j = i + l - 1;

            for (int k = i; k < j; k += 1)
            {

                ll x = dp[i][k] + dp[k + 1][j] + (a[i - 1] * a[j] * a[k]);
                dp[i][j] = min(dp[i][j], x);
            }
        }
    }
    for (int i = 2; i <= n; i += 1)
    {

        for (int j = 2; j <= n; j += 1)
        {

            if (i > j)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << dp[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout << dp[2][n] << endl;
}
int32_t main()
{
    int t = 1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
