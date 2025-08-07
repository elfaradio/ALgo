

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

bool ok(vector<vector<ll>> &v, int row, int col, int n)
{
    for (int i = 0; i < row; i += 1)
    {
        if (v[i][col])
            return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++)
    {
        if (v[i][j])
            return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--)
    {
        if (v[i][j])
            return false;
    }
    return true;
}

vector<ll> ans;
bool ss(vector<vector<ll>> &v, int row, int n)
{
    if (row == n)
        return true;
    for (int col = 0; col < n; col++)
    {
        if (ok(v, row, col, n))
        {
            v[row][col] = 1;
            ans.push_back(col + 1);
            if (ss(v, row + 1, n))
                return true;
            v[row][col] = 0;
            ans.pop_back();
        }
    }
    return false;
}
void solve()
{
    // By Farhadul Islam
    // Only Brute Force Bhai
    ll n;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(n, 0));
    ss(v, 0, n);
    if (ans.size() == 0)
    {
        cout << "not possible";
        return;
    }
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
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
