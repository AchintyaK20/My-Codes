#include<bits/stdc++.h>
#define MAX 100
int n, a[MAX];

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i, h, l, m, key;
	cin >> n;
	for (i = 0 ; i < n ; i++)
	{
		cin >> a[i];
	}
	l = 0;
	h = n - 1;
	while (l <= h)
	{
		m = (l + h) / 2;
		if ((m == 0 || a[m - 1] <= a[m]) && (m == n - 1 || a[m + 1] <= a[m]))
		{
			cout << m;
			break;
		}
		else if (a[m] < a[m - 1])
		{
			h = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}

}