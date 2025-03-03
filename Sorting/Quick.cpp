

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
ll Part(vector<ll> &arr, ll low, ll high)
{
    ll pivot = arr[low];
    ll i = low;
    ll j = high;
    while (i < j)
    {
        while (arr[i] <= pivot and i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot and j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
vector<ll> qsort(vector<ll> &arr, ll low, ll high)
{
    if (low < high)
    {
        ll pi = Part(arr, low, high);
        qsort(arr, low, pi - 1);
        qsort(arr, pi + 1, high);
    }
    return arr;
}
void solve()
{
    // By Farhadul Islam
    // Only Brute Force Bhai

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i += 1)
    {
        cin >> a[i];
    }
    vector<ll> ans;
    qsort(a, 0, n - 1);
    for (auto x : a)
    {
        cout << x << " ";
    }
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
