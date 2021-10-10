#include "bits/stdc++.h"
#define FAST_IO              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define REP(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define endl "\n"
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define MOD 1000000007
using namespace std;

const int MAX_N = 1e5 + 5;
int t, n, a[MAX_N];

int main()
{
    FAST_IO;
    string str;
    cin >> str;
    int n = str.length();
    int total = pow(2, n);
    for (int counter = 0; counter < total; counter++)
    {
        for (int j = 0; j < n; j++)
        {
            if (counter & (1 << j))
            {
                cout << str[j];
            }
        }
        cout << endl;
    }
    return 0;
}