// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getMid(int s, int e)
{
    return s + (e - s) / 2;
}

ll constructSTUtil(int *arr, int ss, int se, ll *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) +
             constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
    return st[si];
}

ll *constructST(int *arr, int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    ll *st = new ll[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

ll getsum(ll *st, int n, int l, int r);
void updateValue(int *, ll *, int, int, int);

// Position this line where user code will be pasted

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int num, query;
        cin >> num >> query;
        int arr[num];
        for (int i = 0; i < num; i++)
            cin >> arr[i];

        ll *st = constructST(arr, num);
        int L, R, index, val;
        char type;
        while (query--)
        {
            cin.ignore(INT_MAX, '\n');
            cin >> type;
            if (type == 'G')
            {
                cin >> L >> R;
                cout << getsum(st, num, L, R) << endl;
            }
            else
            {
                cin >> index >> val;
                updateValue(arr, st, num, index, val);
            }
        }
    }

    return 0;
}
// } Driver Code Ends

// User function template for C++

// arr : given array
// n : size of arr
// index : need to update
// new_val : given value to which we need to update index
// st : constructed segment-tree
// Function use to update the value present in given array arr at index to
// new_val

ll GETSUM(int l, int r, int ss, int se, int si, ll *st)
{
    if (l > se || r < ss)
    {
        return 0;
    }
    if (l <= ss && r >= se)
    {
        return st[si];
    }
    int mid = getMid(ss, se);
    return GETSUM(l, r, ss, mid, 2 * si + 1, st) +
           GETSUM(l, r, mid + 1, se, 2 * si + 2, st);
}
void UPDATE(int ss, int se, int index, int diff, int si, ll *st)
{
    if (index < ss || index > se)
    {
        return;
    }
    st[si] = st[si] + diff;
    if (ss < se)
    {
        int mid = getMid(ss, se);
        UPDATE(ss, mid, index, diff, 2 * si + 1, st);
        UPDATE(mid + 1, se, index, diff, 2 * si + 2, st);
    }
}
void updateValue(int *arr, ll *st, int n, int index, int new_val)
{
    int diff = new_val - arr[index];
    arr[index] = new_val;
    UPDATE(0, n - 1, index, diff, 0, st);
}
ll getsum(ll *st, int n, int l, int r)
{
    ll sum = GETSUM(l, r, 0, n - 1, 0, st);
    return sum;
}
