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

ll pow(ll x, ll n)
{
	ll res = 1;
	x = x % MOD7;
	while (n > 0)
	{
		if (n & 1)			//	If y is odd, multiply x with result.
		{
			res = (res * x) % MOD7;
		}
		x = (x * x) % MOD7;		//	x = x^2
		n = n >> 1;		//	n = n/2
	}
	return res;
}
int main()
{
	SPEED;
	ll x, n;
	cin >> x >> n;
	ll ans = pow(x, n);
	cout << ans;
	return 0;
}