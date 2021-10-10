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
#define MOD7 1000000007
using namespace std;

#define MAX 100005

ll C[2 * MAX];
ll n, m;

int merge(ll A[], ll B[])
{
    int l1 = 0, l2 = 0, cnt = 0;
    while ( l1 < n || l2 < m )
    {
        if ( l1 < n && l2 < m )
        {
            if ( A[l1] < B[l2] )
            {
                C[cnt++] = A[l1];
                l1++;
            }
            else if ( A[l1] > B[l2] )
            {
                C[cnt++] = B[l2];
                l2++;
            }
            else
            {
                C[cnt++] = B[l2];
                l1++;
                l2++;
            }
        }
        else if ( l1 < n )
        {
            C[cnt++] = A[l1];
            l1++;
        }
        else if ( l2 < m )
        {
            C[cnt++] = B[l2];
            l2++;
        }
    }
    return cnt;
}

int main()
{
    SPEED;
    int i;
    cin >> n >> m;
    ll A[n], B[m];
    for (i = 0 ; i < n ; i++)
    {
        cin >> A[i];
    }
    for (i = 0 ; i < m ; i++)
    {
        cin >> B[i];
    }
    int cnt = merge(A, B);
    for (i = 0 ; i < cnt ; i++)
    {
        cout << C[i] << " ";
    }
    return 0;
}