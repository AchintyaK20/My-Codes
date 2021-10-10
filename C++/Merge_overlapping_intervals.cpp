#include "bits/stdc++.h"
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define rep(i,a,b) for (int i = a; i < b; i++)
#define F first
#define S second
#define endl "\n"
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define MOD 1000000007
using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.F < b.F);
}

int main()
{
    FAST_IO;
    int n;
    cin >> n;
    vector <pair<int, int>> v;
    rep(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        v.pb(mp(x, y));
    }
    sort(v.begin(), v.end());
    int res = 0;
    rep(i, 1, n)
    {
        if (v[res].S >= v[i].F)
        {
            v[res].S = max(v[res].S, v[i].S);
            v[res].F = min(v[res].F, v[i].F);
        }
        else
        {
            res++;
            v[res] = v[i];
        }
    }
    rep(i, 0, res + 1)
    {
        cout << v[i].F << " " << v[i].S << endl;
    }
    return 0;
}