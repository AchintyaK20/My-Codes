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
using namespace std;

#define NIL -1
#define MAX 100
int lookup[MAX];

void initialize()
{
	int i;
	for (i = 0 ; i < MAX ; i++)
	{
		lookup[i] = NIL;
	}
}

int fib(int n)
{
	if (lookup[n] == NIL)
	{
		if (n <= 1)
		{
			lookup[n] = n;
		}
		else
		{
			lookup[n] = fib(n - 1) + fib(n - 2);
		}
	}
	return lookup[n];
}
int main()
{
	SPEED;
	int n;
	cin >> n;
	initialize();
	int p = fib(n);
	cout<<p;
	return 0;
}