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
	int n, i, f;
	cin >> n;
	int a[n];
	for (i = 0 ; i < n ; i++)
	{
		cin >> a[i];
	}
	int prefixSum[n + 1];
	prefixSum[0] = 0;
	for (i = 1 ; i <= n ; i++)
	{
		prefixSum[i] = prefixSum[i - 1] + a[i - 1];
	}
	for (i = 0 ; i <= n ; i++)
	{
		cout << prefixSum[i] << " ";
	}
	cout<<"\n";
	f = 0;
	for (i = 0 ; i <= n ; i++)
	{
		if (prefixSum[i - 1] == prefixSum[n] - prefixSum[i])
		{
			f = 1;
			break;
		}
	}
	if (f == 1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}