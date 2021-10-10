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
	int t, i, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int a[n];
		int res = 0;
		for (i = 0 ; i < n ; i++)
		{
			cin >> a[i];
		}
		int leftMax[n], rightMax[n];
		leftMax[0] = a[0];
		for (i = 1 ; i < n ; i++)
		{
			leftMax[i] = max(leftMax[i - 1], a[i]);
		}
		rightMax[n - 1] = a[n - 1];
		for (i = n - 2 ; i >= 0 ; i--)
		{
			rightMax[i] = max(rightMax[i + 1], a[i]);
		}
		for (i = 0 ; i < n ; i++)
		{
			res = res + min(leftMax[i], rightMax[i]) - a[i];
		}
		cout<<res<<endl;
	}
	return 0;
}