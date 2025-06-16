

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
const ll N = 1e5 + 28;
vector<ll> g[N];
bool vis[N];

void dfs(ll u)
{
    vis[u] = true;
    for (auto c : g[u])
    {
        if (!vis[c])
        {
            dfs(c);
        }
    }
}

void solve()
{
    // By Farhadul Islam
    // Only Brute Force Bhai
    // cmp'

    ll n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i += 1)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i += 1)
    {
        if (!vis[i])
        {
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;
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
