// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int  t, n, i, k;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		int a[n];
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		unordered_map<int, int> u;
		for (i = 0 ; i < k ; i++)
		{
			u[a[i]]++;
		}
		cout << u.size() << " ";
		int l = 0, r = k;
		while (r < n)
		{
			u[a[l]]--;
			if (u[a[l]] == 0)
			{
				u.erase(a[l]);
			}
			u[a[r]]++;
			cout << u.size() << " ";
			l++; r++;
		}
		cout << endl;
	}

	return 0;
}