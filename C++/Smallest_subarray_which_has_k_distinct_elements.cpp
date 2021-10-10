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
	int n, K;
	cin >> n;
	int A[n];
	for (int i = 0 ; i < n ; i++)
	{
		cin >> A[i];
	}
	cin >> K;
	int l = 0, r = 0, ans = INT_MAX;
	map <int , int >  cnt;
	unordered_set<int> s;
	while ( l < n )
	{
		while ( r < n && s.size() < K )
		{
			s.insert(A[r]);
			cnt[A[r]]++;
			r++;
		}
		if (s.size() >= K)
		{
			ans = min(ans, r - l);
		}
		if ( cnt[A[l]] == 1 )
		{
			s.erase(A[l]);
		}
		cnt[A[l]]--;
		l++;
	}

	if ( ans == INT_MAX )
	{
		ans = -1;
	}

	cout << ans << endl;
	return 0;
}