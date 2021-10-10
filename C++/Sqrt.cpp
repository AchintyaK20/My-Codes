#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long x;
	cin>>x;
	long long  l = 0, m, h = x, ans = 0;
	while (l <= h)
	{
		m = (l + h) / 2;
		if (m * m == x)
		{
			ans = m;
			break;
		}
		else if (m * m > x && (m - 1) * (m - 1) <= x)
		{
			ans = m - 1;
			break;
		}
		else if (m * m > x)
			h = m - 1;
		else
			l = m + 1;
	}
	cout<<ans;
}