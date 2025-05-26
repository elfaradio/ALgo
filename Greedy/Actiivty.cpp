

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
    vector<ll> start(n);
    vector<ll> end(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> start[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> end[i];
    }
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++)
    {
        v.push_back({end[i], start[i]});
    }
    ll ans = 0;
    sort(v.begin(), v.end());
    ll l = -1;
    for (int i = 0; i < n; i += 1)
    {
        if (v[i].second > l)
        {
            ans++;
            l = v[i].first;
        }
    }
    cout << ans << endl;
    // Time Complexity: O(n log n)
}

int32_t main()
{
    int t = 1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        solve();
    }
}
