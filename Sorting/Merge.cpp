

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
void merge(vector<ll> &arr, ll low, ll mid, ll high)
{
    vector<int> temp;
    ll l = low;
    ll r = mid + 1;
    while (l <= mid and r <= high)
    {
        if (arr[l] <= arr[r])
        {
            temp.push_back(arr[l++]);
        }
        else
        {
            temp.push_back(arr[r++]);
        }
    }
    while (l <= mid)
    {
        temp.push_back(arr[l++]);
    }
    while (r <= high)
    {
        temp.push_back(arr[r++]);
    }
    for (int i = low; i <= high; i += 1)
    {
        arr[i] = temp[i - low];
    }
}
void mergesort(vector<ll> &arr, ll low, ll high)
{
    if (low >= high)
    {
        return;
    }
    ll mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
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
    mergesort(a, 0, n - 1);
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
