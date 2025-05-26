

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

ll f(vector<ll> &v, ll n, ll s)
{
    if (s == 0)
    {
        return 1;
    }
    if (n == 0 or s < 0)
    {
        return 0;
    }
    ll pic = f(v, n, s - v[n - 1]);
    ll nonpic = f(v, n - 1, s);
    return pic + nonpic;
}
void solve()
{
    // By Farhadul Islam
    // Only Brute Force Bhai
    ll n, m;
    cin >> n >> m;
    vector<ll> v(m);
    for (ll i = 0; i < m; i += 1)
    {
        cin >> v[i];
    }
    // sort(v.rbegin(), v.rend());

    // Insertion sort// O(n^2)
    for (int i = 0; i < m; i += 1)
    {
        ll j = i - 1;
        ll x = v[i];
        while (j <= 0 and v[j] > v[i])
        {
            swap(v[j], v[i]);
            j -= 1;
        }
        v[j + 1] = x;
    }
    // Selection sort O(n^2)
    for (int i = 0; i < m - 1; i += 1)
    {

        int mn = i;
        for (int j = i + 1; j < m; j += 1)
        {
            if (v[j] < v[mn])
            {
                mn = j;
            }
        }
        swap(v[i], v[mn]);
    }

    // Bubble sort O(n^2)
    // for (int i = 0; i < m - 1; i += 1)
    // {
    //     for (int j = 0; j < m - i - 1; j += 1)
    //     {
    //         if (v[j] > v[j + 1])
    //         {
    //             swap(v[j], v[j + 1]);
    //         }
    //     }
    // }
    for (int i = 0; i < m; i += 1)
    {
        cout << v[i] << " ";
    }

    ll ans = 0;

    // greedy approach
    // for (int i = 0; i < n; i += 1)
    // {
    //     ans += (n / v[i]);
    //     n -= (n / v[i]) * v[i];
    // }
    ans = 0;
    // recursive approach
    // ans = f(v, v.size(), n);

    cout << ans << "\n";
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
