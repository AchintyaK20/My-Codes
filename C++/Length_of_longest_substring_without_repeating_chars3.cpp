#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define unm unordered_map<char,int>
#define pb push_back

const int N = 100005;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 1, cnt = 0, sum = 0, p = 0;
        string s;
        cin >> s;
        n = s.length();
        unm mp;
        for (i = 0; i < n; i++)
        {
            if (mp.find(s[i]) != mp.end())
            {
                ans = max(ans, i - p);
                int l = mp[s[i]];
                for (j = p; j <= l; j++)
                    mp.erase(s[j]);
                p = l + 1;
            }
            mp[s[i]] = i;
        }
        ans = max(ans, i - p);
        cout << ans;
    }
    return 0;
}
