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

int normalKadane()
{
	int maxEnding = a[0], res = a[0];
	REP(i, 1, n)
	{
		maxEnding = max(maxEnding + a[i], a[i]);
		res = max(res, maxEnding);
	}
	return res;
}
int main()
{
	FAST_IO;
	cin >> n;
	REP(i, 0, n)
	{
		cin >> a[i];
	}
	int maxNormal = normalKadane();
	if (maxNormal < 0)
	{
		cout << maxNormal;
	}
	else
	{
		int arrSum = 0;
		REP(i, 0, n)
		{
			arrSum += a[i];
			a[i] = -a[i];
		}
		int maxCircular = arrSum + normalKadane();
		int ans = max(maxCircular, maxNormal);
		cout << ans;
	}
	return 0;
}