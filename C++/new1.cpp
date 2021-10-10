#include "bits/stdc++.h"
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define MP make_pair
#define PB push_back
#define vi vector<int>
#define pi pair<int, int>
#define REP(i,a,b) for (int i = a; i < b; i++)
#define F first
#define S second
#define endl "\n"
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define MOD7 1000000007
using namespace std;

ll constST(ll arr[] , ll ss, ll se, ll *st, ll si)
{
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}
	ll mid = (ss + se) / 2;
	st[si] = max(constST(arr, ss, mid, st, si * 2 + 1), constST(arr, mid + 1, se, st, si * 2 + 2));
	return st[si];
}
ll *constructST(ll arr[], ll n)
{
	ll x = (ll)(ceil(log2(n)));

	ll max_size = 2 * (ll)pow(2, x) - 1;

	ll *st = new ll[max_size];

	constST(arr, 0, n - 1, st, 0);
	return st;
}
ll MaxUtil(ll* st, ll ss, ll se, ll l, ll r, ll si)
{

	if (l <= ss && r >= se)
		return st[si];
	if (se < l || ss > r)
		return -1;

	ll mid = (ss + se) / 2;

	return max(MaxUtil(st, ss, mid, l, r, 2 * si + 1), MaxUtil(st, mid + 1, se, l, r, 2 * si + 2));
}
void Query1(ll b, ll k, ll taste[], ll N)
{
	taste[b - 1] = k;
}
void Query2(ll b, ll c, ll height[], ll taste[], ll N, ll *st)
{
	if (b > c)
	{
		if (MaxUtil(st, 0, N - 1, c - 1, b - 2, 0) >= height[b - 1])
		{
			cout << "-1" << endl;
			return;
		}
		else
		{
			
		}
	}
	else if (b < c)
	{
		if (MaxUtil(st, 0, N - 1, b, c - 1, 0) >= height[b - 1])
		{
			cout << "-1" << endl;
			return;
		}
		else
		{
			ll i = c-1;
			stack<ll> s;
			s.push(c-1);
			ll ans = taste[c-1];
			while(i>=b-1)
			{
				if(height[i] > height[s.top()])
				{
					s.push(i);
					ans += taste[i];
				}
				i--;
			}
			cout<<ans<<endl;
		}
	}
	else
	{
		cout << taste[b - 1] << endl;
		return;
	}

}

int main()
{
	FAST_IO;
	ll N, Q;
	cin >> N >> Q;
	ll height[N];
	REP(i, 0, N)
	{
		cin >> height[i];
	}
	ll taste[N];
	REP(i, 0, N)
	{
		cin >> taste[i];
	}
	ll x, b, c;
	ll *st = constructST(height, N);
	REP(i, 1, Q + 1)
	{
		cin >> x >> b >> c;
		if (x == 1)
			Query1(b, c, taste, N);
		else
			Query2(b, c, height, taste, N, st);
	}
	return 0;
}