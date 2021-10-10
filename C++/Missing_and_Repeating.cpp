#include "bits/stdc++.h"
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define REP(i,a,b) for (int i = a; i < b; i++)
#define F first
#define S second
#define endl "\n"
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define MOD 1000000007
using namespace std;

int main()
{
    FAST_IO;
    int temp = 0, n;
    cin >> n;
    int arr[n];
    REP(i, 0, n)
    {
        cin >> arr[i];
    }
    int repeating = 0, missing = 0;
    REP(i, 0, n)
    {
        temp = arr[abs(arr[i]) - 1];
        if (temp < 0 )
        {
            repeating = abs(arr[i]);
        }
        arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }

    REP(i, 0, n)
    {
        if (arr[i] > 0 )
        {
            missing = i + 1;
        }
    }
    cout << repeating << " " << missing;
    return 0;
}