#include <bits/stdc++.h>
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
    double n, x, y;
    cin >> n;
    vector<double> a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    cin >> x >> y;
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (a[mid] >= x && a[mid] <= y)
        {
            mid++;
        }
        else if (a[mid] > y)
        {
            swap(a[high], a[mid]);
            high--;
        }
        else
        {
            swap(a[mid], a[low]);
            low++;
            mid++;
        }
    }
    rep(i, 0, n)
    {
        cout << a[i] << " ";
    }
    return 0;
}