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
	int x;
	cin >> x;
	if (x && !(x & (x - 1)))
	{
		cout << "Power of 2";
	}
	else
	{
		cout << "Not Power of 2";
	}
	return 0;
}