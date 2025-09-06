#include <iostream>
#include <vector>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define pi pair<int, int>
#define umap unordered_map<int, int>
using namespace std;

void sieve(int N)
{
	vector<bool> isPrime(N + 1, true);
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i <= N; ++i)
	{
		if (isPrime[i] == true)
		{
			// Mark all the multiples of i as composite numbers
			for (int j = i * i; j <= N ; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	for (int i = 0 ; i <= N ; i++)
	{
		if (isPrime[i])
		{
			cout << i << " ";
		}
	}
}

int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;
	sieve(n);
	return 0;
}
