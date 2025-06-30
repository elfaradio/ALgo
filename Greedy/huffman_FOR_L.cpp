#include <bits/stdc++.h>
using namespace std;

struct F
{
    char c;
    long long cnt;
    F *l, *r;
    F(char c, long long cnt)
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

void f(F *matha, string cd, unordered_map<char, string> &code)
{
    if (matha == nullptr)
        return;
    if (matha->l == nullptr && matha->r == nullptr)
    {
        code[matha->c] = cd;
    }
    f(matha->l, cd + '0', code);
    f(matha->r, cd + '1', code);
}

void hfman(string &s)
{
    unordered_map<char, long long> hs;
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
        long long sum = l->cnt + r->cnt;
        F *ss = new F('*', sum);
        ss->l = l;
        ss->r = r;
        pq.push(ss);
    }

    F *matha = pq.top();
    unordered_map<char, string> code;
    f(matha, "", code);

    for (auto cc : code)
    {
        cout << cc.first << " " << cc.second << "\n";
    }

    string ans = "";
    for (auto cc : s)
    {
        cout << code[cc] << " ";
        ans += code[cc];
    }
    cout << "\n";
    cout << ans << "\n";
}

int main()
{
    string s;
    getline(cin, s);
    hfman(s);
}
