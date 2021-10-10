#include<bits/stdc++.h>
#define MAX 100
int n, a[MAX];

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i, h, l, m, key;
	cin >> n >> key;
	for (i = 0 ; i < n ; i++)
	{
		cin >> a[i];
	}
	l = 0;
	h = n;
	while (h - l > 1)
	{
		m = (l + h) / 2;
		if (a[m] <= key)
		{
			l = m;
		}
		else
		{
			h = m;
		}
	}
	cout << l;

}