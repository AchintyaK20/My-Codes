/*Brian-Karninghan's Algorithm*/

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
	int x, res = 0;
	cin >> x;
	while (x > 0)
	{
		x = x & (x - 1);
		res++;
	}
	cout << "No. of set bits: " << res;
	return 0;
}