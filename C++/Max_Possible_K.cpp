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
using namespace std;
int k = 0, n = 0;

bool isPossible(int mid, int a[], int k)
{
	int i;
	int s = accumulate(a, a + mid, 0);
	if (s > k)
	{
		return false;
	}
	for (i = 1 ; i <= n - mid ; i++)
	{
		s = s - a[i - 1] + a[i + mid - 1];
		if (s > k)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	SPEED;
	int i, l, h, mid, x;
	cin >> n;
	int a[n];
	for (i = 0 ; i < n ; i++)
	{
		cin >> a[i];
	}
	cin >> k;
	l = 0;
	h = n + 1;
	while (h - l > 1)
	{
		mid = (l + h) / 2;
		if (isPossible(mid, a, k))
		{
			l = mid;
		}
		else
		{
			h = mid;
		}
	}
	cout << l;
	return 0;
}