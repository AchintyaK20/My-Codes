#include<bits/stdc++.h>
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define pi pair<int, int>
#define umap unordered_map<int, int>
#define MOD7 1000000007
using namespace std;

int main()
{
    SPEED;
    int t, n, l, r, gSum, i;
    cin >> t;
    while (t--)
    {
        cin >> n >> gSum;;
        int a[n];
        for (i = 0 ; i < n ; i++)
        {
            cin >> a[i];
        }
        int prefix[n + 1];
        prefix[0] = 0;
        for (i = 1 ; i <= n ; i++)
        {
            prefix[i] = prefix[i - 1] + a[i - 1];
        }
        l = 0; r = 0;
        int f = 0;
        while (l < n)
        {
            if ((prefix[r] - prefix[l]) == gSum)
            {
                f = 1;
                break;
            }
            else if ((prefix[r] - prefix[l]) < gSum)
            {
                r++;
            }
            else
            {
                l++;
            }
        }
        if (f == 1)
        {
            cout << l + 1 << " " << r << "\n";
        }
        else
        {
            cout << "-1" << "\n";
        }
    }
    return 0;
}