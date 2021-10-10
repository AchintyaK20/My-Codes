#include "bits/stdc++.h"
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vvi vector<vi> 
#define pi pair<int, int>
#define rep(i,a,b) for (int i = a; i < b; i++)
#define F first
#define S second
#define endl "\n"
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define MOD 1000000007
using namespace std;

int longest(int a[], int n, int sum)
{
	umap u;
	int pre = 0, res = INT_MIN;
	rep(i,0,n)
	{
		pre += a[i];
		if(u.find(pre - sum) != u.end())
		{
			res = max(res, i-u[pre-sum]);
		}
		else if(pre == sum)
		{
			res = i+1;
		}
		else
		{
			u.insert(mp(pre, i));
		}
	}
	return res;
}
int main()
{
	FAST_IO;
	int n,sum;
	cin>>n>>sum;
	int a[n];
	rep(i,0,n)
	{
		cin>>a[i];
	}
	cout<<longest(a,n,sum);
	return 0;
}