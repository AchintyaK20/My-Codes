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
#define all(x) x.begin(), x.end()
#define endl "\n"
#define ceil(a,b) ceil((float)a/b)
#define floor(a,b) floor((float)a/b)
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define MOD 1000000007
using namespace std;

int solve()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    int k = n - 1;
    int temp[k];
    for (int i = 0 ; i < k ; i++)
    {
        temp[i] = (a[i] - a[i + 1]);
    }
    int res = INT_MIN;
    for (int i = 0 ; i < k ; )
    {
        int x = temp[i];
        int c = 0;
        while (x == temp[i])
        {
            i++;
            c++;
        }
        res = max(res, c + 1);
    }
    return res;
}
int main()
{
    FAST_IO;
    int T;
    cin >> T;
    rep(tc, 1, T + 1)
    {
        cout << "Case #" << tc << ": " << solve();
        cout << endl;
    }
    return 0;
}