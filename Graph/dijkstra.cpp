

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
const ll N = 1000;
vector<vector<pair<ll, ll>>> adj(N);
vector<bool> vis(N, false);
vector<ll> dist(N, LLONG_MAX);
void dijkstra(ll src, ll n)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        // if (d > dist[u])
        //   continue;
        for (auto [v, w] : adj[u])
        {

            if (w + d < dist[v])
            {
                dist[v] = w + d;
                pq.push({dist[v], v});
            }
        }
    }
}
void solve()
{
    // By Farhadul Islam
    // Only Brute Force Bhai
    ll n, e;
    cin >> n >> e;

    for (ll i = 0; i < e; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(0, n);
    // cout << dist[n - 2] << endl;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == LLONG_MAX)

            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
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
