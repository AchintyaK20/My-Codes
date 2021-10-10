#include "bits/stdc++.h"
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define REP(i,a,b) for (int i = a; i < b; i++)
#define F first
#define S second
#define br "\n"
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define MOD 1000000007
using namespace std;

int main()
{
	FAST_IO;
	int t;
	cin >> t;
	while (t--)
	{
		ll n, m, x, y, ans = 0, total = 0;
		cin >> n >> m >> x >> y;
		total = n * m;
		if (total == 1)
		{
			cout << x << br;
			continue;
		}
		if (total % 2 != 0)
		{
			if (y / 2 >= x)
			{
				ans = total * x;
				cout << ans << br;
				continue;
			}
			else
			{
				if (y == 1)
				{
					ans = (total / 2) + 1;
					cout << ans << br;
					continue;
				}
				else if (y < x)
				{
					int sum1 = (total/2) + 1;
					ans = y*sum1;
					cout << ans << br;
					continue;
				}
				else
				{
					int temp = (total / 2) + 1;
					int sum1 = x;
					int sum2 = y - x;
					int ans = sum1 * temp + sum2 * (total - temp);
					cout << ans << br;
					continue;
				}
			}
		}
		else
		{
			if (y / 2 >= x)
			{
				ans = total * x;
				cout << ans << br;
				continue;
			}
			else
			{
				if (y == 1)
				{
					ans = total / 2;
					cout << ans << br;
					continue;
				}
				else if (y < x)
				{
					int sum1 = 1;
					int sum2 = y - 1;
					ans = sum1 * (total / 2) + sum2 * (total / 2);
					cout << ans << br;
					continue;
				}
				else
				{
					int sum1 = x;
					int sum2 = y - x;
					ans = sum1 * (total / 2) + sum2 * (total / 2);
					cout << ans << br;
					continue;
				}
			}
		}
	}
	return 0;
}