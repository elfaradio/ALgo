#include <bits/stdc++.h>
using namespace std;
#define ll long long

class DSU
{
    vector<ll> parent, sz;

public:
    DSU(ll n)
    {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for (ll i = 1; i <= n; i++)
            parent[i] = i;
    }

    ll Find(ll v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = Find(parent[v]);
    }

    void Union(ll a, ll b)
    {
        a = Find(a);
        b = Find(b);
        if (a != b)
        {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

int main()
{
    ll n, e;
    cin >> n >> e;

    vector<tuple<ll, ll, ll>> edges; // {weight, u, v}

    for (ll i = 0; i < e; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

   
    sort(edges.begin(), edges.end());

    
    DSU dsu(n);
    ll total_weight = 0;
    vector<pair<ll, ll>> mst_edges;

    for (auto &[w, u, v] : edges)
    {
        if (dsu.Find(u) != dsu.Find(v))
        {
            dsu.Union(u, v);
            total_weight += w;
            mst_edges.push_back({u, v});
        }
    }

    // Output
    cout << "Total weight of MST: " << total_weight << "\n";
    cout << "Edges in MST:\n";
    for (auto &[u, v] : mst_edges)
        cout << u << " - " << v << "\n";

    return 0;
}
