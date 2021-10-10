#include<bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define F first
#define S second
#define endl "\n"
#define umap unordered_map<int, int>
#define MOD7 1000000007
using namespace std;

struct comp
{
	template<typename T>
	bool operator()(const T& l, const T& r) const
	{
		if (l.second != r.second)
			return l.second > r.second;

		return l.first < r.first;
	}
};

void solve()
{
	int n, i;
	cin >> n;
	int a[n];
	for (i = 0 ; i < n ; i++)
	{
		cin >> a[i];
	}
	map<int, int> mymap;
	for (i = 0 ; i < n ; i++)
	{
		mymap[a[i]]++;
	}
	set<pair<int, int>, comp> set1(mymap.begin(), mymap.end());
	vi v;
	for(auto x : set1)
	{
		while(x.S != 0)
		{
			v.pb(x.F);
			x.S--;
		}
	}
	for(i=0 ; i<v.size() ; i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	FAST_IO;
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}