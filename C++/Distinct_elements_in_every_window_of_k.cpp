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

const int MAX_N = 1e5 + 5;
int t, n, a[MAX_N];

int main()
{
	FAST_IO;
	int k;
	cin >> n >> k;
	REP(i, 0, n)
	{
		cin >> a[i];
	}
	umap u;
	int dist = 0;
	REP(i, 0, k)
	{
		if (u[a[i]] == 0)
		{
			dist++;
		}
		u[a[i]]++;
	}
	cout << dist << " ";
	REP(i, k, n)
	{
		if (u[a[i - k]] == 1)
		{
			dist--;
		}
		u[a[i - k]]--;
		if (u[a[i]] == 0)
		{
			dist++;
		}
		u[a[i]]++;
		cout << dist << " ";
	}

	return 0;
}