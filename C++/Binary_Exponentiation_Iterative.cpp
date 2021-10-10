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

ll power(ll x, ll y)
{
	ll res = 1;	 // Initialize result

	x = x % MOD; // Update x if it is more than or equal to MOD
	if (x == 0)
	{
		return 0; // In case x is divisible by p;
	}
	while (y > 0)
	{
		if (y & 1)	// If y is odd, multiply x with result
		{
			res = (res * x) % MOD;
		}								
		// y must be even now
		y = y >> 1; // y = y/2
		x = (x * x) % MOD;
	}
	return res;
}
int main()
{
	int N, R;
	cin >> N >> R;
	cout << power(N, R);
}