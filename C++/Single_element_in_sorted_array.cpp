#include<bits/stdc++.h>
#define MAX 100
int n, a[MAX];

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i, h, l, m;
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
		if (m == 0 && a[m + 1] != a[m])
		{
			cout << a[m];
			break;
		}
		else if (m == n - 1 && a[m] != a[n - 2])
		{
			cout << a[m];
			break;
		}
		else if (a[m] == a[m - 1])
		{
			if ((m - 1) % 2 != 0)
			{
				h = m - 1;
			}
			else
			{
				l = m + 1;
			}
		}
		else if (a[m] == a[m + 1])
		{
			if (m % 2 == 0)
			{
				l = m + 1;
			}
			else
			{
				h = m - 1;
			}
		}
		else 
		{
			cout << a[m];
			break;
		}
	}
}