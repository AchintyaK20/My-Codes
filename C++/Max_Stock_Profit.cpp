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
	int n, i, profit = 0, buy, sell;
	cin >> n;
	int price[n];
	for (i = 0 ; i < n ; i++)
	{
		cin >> price[i];
	}
	i = 0;
	while (i < n - 1)
	{
		while ((i < n - 1) && (price[i + 1] <= price[i]) )
		{
			i++;
		}
		if (i == n - 1)
		{
			break;
		}
		buy = i;
		i++;
		while ((i < n) && (price[i] >= price[i - 1]) )
		{
			i++;
		}
		sell = i - 1;
		profit = profit + (price[sell] - price[buy]);
	}
	cout << profit;
	return 0;
}