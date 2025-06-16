

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
void solve()
{
    // By Farhadul Islam
    // Only Brute Force Bhai
    double m, n;
    cin >> m >> n;
    vector<double> p(n), w(n);

    for (int i = 0; i < n; i += 1)
        cin >> p[i];
    for (int i = 0; i < n; i += 1)
        cin >> w[i];

    vector<pair<double, ll>> avg(n);
    for (int i = 0; i < n; i += 1)
    {
        avg[i] = {p[i] / w[i], i};
    }

    sort(avg.begin(), avg.end());
    reverse(avg.begin(), avg.end());

    double ans = 0;
    ll i = 0;
    while (i < n and m > 0)
    {
        ll j = avg[i].second;
        if (w[j] <= m)
        {
            ans += p[j];
            m -= w[j];
        }
        else
        {
            ans += m * avg[i].first;
            m = 0;
        }
        i += 1;
    }

    cout << fixed << setprecision(12) << ans << "\n";

    // o(nlogn)
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
