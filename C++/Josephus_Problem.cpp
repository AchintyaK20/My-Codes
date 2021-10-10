#include "bits/stdc++.h"
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define MP make_pair
#define PB push_back
#define vi vector<int>
#define pi pair<int, int>
#define REP(i,a,b) for (int i = a; i < b; i++)
#define F first
#define S second
#define endl "\n"
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define MOD7 1000000007
using namespace std;

int jos(int n, int k)
{
    if (n == 1)
        return 1;
    return (jos(n - 1, k) + k-1) % n + 1;
}
int main()
{
    FAST_IO;
    int n, k;
    cin >> n >> k;
    cout << jos(n, k);
    return 0;
}