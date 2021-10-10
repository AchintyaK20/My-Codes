#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main()
{
    SPEED;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<int> s1, s2;
    vector<int> ps, ns;
    ps.push_back(-1);
    s1.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!s1.empty() && a[i] <= a[s1.top()])
        {
            s1.pop();
        }
        ps.push_back(s1.empty() ? -1 : s1.top());
        s1.push(i);
    }
    s2.push(n - 1);
    ns.push_back(n);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s2.empty() && a[i] <= a[s2.top()])
        {
            s2.pop();
        }
        ns.push_back(s2.empty() ? n : s2.top());
        s2.push(i);
    }
    reverse(ns.begin(), ns.end());
    // for (int i = 0; i<n; i++)
    // {
    //     cout << ps[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i<n; i++)
    // {
    //     cout << ns[i] << " ";
    // }
    // cout << endl;
    int res = -INF;
    for (int i = 0; i < n; i++)
    {
        int cur = a[i];
        cur += (i - ps[i] - 1) * a[i];
        cur += (ns[i] - i - 1) * a[i];
        res = max(res, cur);
    }
    cout << res;
    return 0;
}