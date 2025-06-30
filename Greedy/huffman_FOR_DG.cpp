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
        if (l->cnt == r->cnt)
            return l->c > r->c;
        return l->cnt > r->cnt;
    }
};

void f(F *matha, string cd, map<char, string> &code)
{
    if (matha == nullptr)
        return;
    if (matha->l == nullptr && matha->r == nullptr)
    {
        code[matha->c] = cd.empty() ? "0" : cd;
    }
    f(matha->l, cd + '0', code);
    f(matha->r, cd + '1', code);
}

void hfman(string &s)
{
    map<char, long long> hs;
    for (auto cc : s)
        hs[cc]++;

    priority_queue<F *, vector<F *>, Sort> pq;
    for (auto &cc : hs)
        pq.push(new F(cc.first, cc.second));

    while (pq.size() != 1)
    {
        F *l = pq.top();
        pq.pop();
        F *r = pq.top();
        pq.pop();
        F *ss = new F('*', l->cnt + r->cnt);
        ss->l = l;
        ss->r = r;
        pq.push(ss);
    }

    F *matha = pq.top();
    map<char, string> code;
    f(matha, "", code);

    cout << "Huffman Codes:\n";
    for (auto cc : code)
    {
        cout << cc.first << ": " << cc.second << "\n";
    }

    string ans = "";
    for (auto ch : s)
    {
        ans += code[ch];
    }

    long long mb = 0;
    vector<string> V;
    int x = 0;
    cout << "\nMessage bits = ";
    for (auto ch : hs)
    {

        if (x > 0)
            cout << " + ";
        long long cc = ch.second * code[ch.first].length();
        cout << to_string(ch.second) + "*" + to_string(code[ch.first].length());
        mb += cc;
        x++;
    }

    cout << " = " << mb << " bits\n";

    long long tb = 0;
    for (auto ch : code)
        tb += (8 + ch.second.length());

    cout << "Table bits   = " << tb << " bits\n";
    cout << "Total bits   = " << (mb + tb) << " bits\n";
}

int main()
{
    string s;
    getline(cin, s);
    hfman(s);
}
