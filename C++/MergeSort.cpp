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

void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1, i, j, k;
    int n2 = r - m;
    int left[n1], right[n2];
    REP(i, 0, n1)
    {
        left[i] = a[l + i];
    }
    REP(j, 0, n2)
    {
        right[j]  = a[m + 1 + j];
    }
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k++] = left[i++];
    }
    while (j < n2)
    {
        a[k++] = right[j++];
    }
}
void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
int main()
{
    FAST_IO;
    int n;
    cin >> n;
    int a[n];
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1);
    REP(i, 0, n)
    {
        cout << a[i] << " ";
    }
    return 0;
}