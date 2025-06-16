
// BY Farhadul Islam

// gfg and gpt
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
struct F
{
    char c;
    ll cnt;
    F *l, *r;
    F(char c, ll cnt)
    {
        this->c = c;
        this->cnt = cnt;
        l = nullptr;
        r = nullptr;
    }
};

struct Sort
{
    bool operator()(F *l, F *r)
    {
        return l->cnt > r->cnt;
    }
};
void f(F *matha, str cd, unordered_map<char, str> &code)
{
    if (matha == nullptr)
        return;
    if (matha->l == nullptr and matha->r == nullptr)
    {
        code[matha->c] = cd;
    }
    f(matha->l, cd + '0', code);
    f(matha->r, cd + '1', code);
}
void hfman(str &s)
{
    unordered_map<char, ll> hs;
    for (auto cc : s)
    {
        hs[cc]++;
    }
    priority_queue<F *, vector<F *>, Sort> pq;
    for (auto cc : hs)
    {
        pq.push(new F(cc.first, cc.second));
    }
    while (pq.size() != 1)
    {

        F *l = pq.top();
        pq.pop();
        F *r = pq.top();
        pq.pop();
        ll sum = 0;
        sum = l->cnt + r->cnt;
        F *ss = new F('*', sum);
        ss->l = l;
        ss->r = r;
        pq.push(ss);
    }

    F *matha = pq.top();
    unordered_map<char, str> code;
    f(matha, "", code);

    for (auto cc : code)
    {
        cout << cc.first << " " << cc.second << endl;
    }

    str ans = "";
    for (auto cc : s)
    {
        cout << code[cc] << " ";
        ans += code[cc];
        // cout << ans << " ";
    }
    // cout << ans << endl;
}
void solve()
{
    // By Farhadul Islam
    // Only Brute Force Bhai

    str s;
    getline(cin, s);
    hfman(s);
}
int32_t main()
{
    int t = 1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    cin.ignore();
    while (t--)
    {
        solve();
    }
}
