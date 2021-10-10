#include "bits/stdc++.h"
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define rep(i,a,b) for (int i = a; i < b; i++)
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
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    int low = 0, mid = 0, high = n - 1;
    int pivot = a[0];
    while (mid <= high)
    {
        if(a[mid] == pivot)
        {
            mid++;
        }
        else if(a[mid] < pivot)
        {
            swap(a[mid], a[low]);
            mid++; low++;
        }
        else
        {
            swap(a[high], a[mid]);
            high--;
        }
    }
    rep(i, 0, n)
    {
        cout << a[i] << " ";
    }
    return 0;
}