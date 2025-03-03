

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
void solve()
{
    // By Farhadul Islam
    // Only Brute Force Bhai
    /*Insertion sort*/
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i += 1)
    {
        cin >> a[i];
    }
    for (ll i = 1; i < n; i += 1)
    {
        ll x = a[i];
        ll j = i - 1;
        while (j >= 0 and a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
    for (ll i = 0; i < n; i += 1)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    /*End of Insertion sort*/
}
int32_t main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
