#include<bits/stdc++.h>
using namespace std;

int LongestsubArray(int arr[], int n)
{
	unordered_map<int, int> umap;
	int i, ans = 0, PS = 0;
	umap.insert(make_pair(0, -1));
	for (i = 0 ; i < n ; i++)
	{
		PS += arr[i];
		if (umap.find(PS) != umap.end())
		{
			ans = max(ans, i - umap[PS]);
		}
		else
		{
			umap.insert(make_pair(PS, i));
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int i, h, l, m, key, n;
	cin >> n;
	int arr[n];
	for (i = 0 ; i < n ; i++)
	{
		cin >> arr[i];
	}
	cout << LongestsubArray(arr, n);
	return 0;
}