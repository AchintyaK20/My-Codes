#include <bits/stdc++.h>
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

int gcd(int a, int b, int* x, int* y)
{
	if (b == 0)
	{
		*x = 1;
		*y = 0;
		return a;
	}
	int x1, y1;
	int d = gcd(b, a % b, &x1, &y1);
	*x = y1;
	*y = x1 - y1 * (a / b);
	return d;
}
int main()
{
	SPEED;
	int a, b, x, y;
	cin >> a >> b;
	int ans = gcd(a, b, &x, &y);
	cout << "GCD = " << ans << "\n";
	cout << "x = " << x << " " << "y = " << y;

	return 0;
}