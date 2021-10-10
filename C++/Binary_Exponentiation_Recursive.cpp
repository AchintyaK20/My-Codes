#include<bits/stdc++.h>
#define MOD7 1000000007
using namespace std;

ll power(ll N, ll R)
{
	if (R == 0)
		return 1;
	ll res = (power(N, R / 2)) % MOD7;
	ll y;
	if (R % 2)
		y = (((res % MOD7) * (res % MOD7) % MOD7) * N) % MOD7;
	else
		y = (res % MOD7) * (res % MOD7) % MOD7;
	return (y + MOD7) % MOD7;
}
int main()
{
	int N, R;
	cin >> N >> R;
	cout << power(N, R);
}