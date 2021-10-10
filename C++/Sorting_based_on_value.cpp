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

int main()
{
	int n,i;
	cin>>n;
	int a[n];
	for(i=0 ; i<n ; i++)
	{
		cin>>a[i];
	}
	map<int,int> m;
	for(i=0 ; i<n ; i++)
	{
		m[a[i]]++;
	}

	// create an empty vector of pairs
	set<pair<int, int>, comp> set1(m.begin(), m.end());

	// print the vector
	for (auto const &pair : set1) 
	{
		cout << pair.F <<" "<< pair.S << '\n';
	}

	return 0;
}