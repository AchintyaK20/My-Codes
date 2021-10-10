// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int getMid(int s, int e) { return s + (e - s) / 2; }

void constructSTUtil(int *arr, int ss, int se, PII *st, int si)
{
    if (ss == se)
    {
        st[si].first = st[si].second = arr[ss];
        return;
    }
    int mid = getMid(ss, se);
    constructSTUtil(arr, ss, mid, st, si * 2 + 1);
    constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);

    st[si].first = min(st[si * 2 + 1].first, st[si * 2 + 2].first);
    st[si].second = max(st[si * 2 + 1].second, st[si * 2 + 2].second);

    return;
}

PII *constructST(int *arr, int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    PII *st = new PII[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

void updateValue(int *, PII *, int, int, int);
PII getMinMax(PII *, int *, int, int, int);

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

        PII *st = constructST(arr, num);
        int L, R, index, val;
        char type;
        while (query--)
        {
            cin.ignore(INT_MAX, '\n');
            cin >> type;
            if (type == 'G')
            {
                cin >> L >> R;
                PII ans = getMinMax(st, arr, num, L, R);
                cout << ans.first << " " << ans.second << endl;
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

//User function template for C++

// arr : given array arr
// st : segment tree of the given array arr
// n :  size of arr array
// qs and qe : index range to find Min and Max value between these indexes.
// PII :  return pair denoting min,max respectively.

PII GETMINMAX(int ss, int se, int si, int l, int r, PII *st, PII &ans)
{
    if (l > se || r < ss)
    {
        return make_pair(INT_MAX, INT_MIN);
    }
    if (l <= ss && r >= se)
    {
        return st[si];
    }
    int mid = getMid(ss, se);
    PII left = GETMINMAX(ss, mid, 2 * si + 1, l, r, st, ans);
    PII right = GETMINMAX(mid + 1, se, 2 * si + 2, l, r, st, ans);
    ans.first = min(left.first, right.first);
    ans.second = max(left.second, right.second);
    return ans;
}
PII getMinMax(PII *st, int *arr, int n, int qs, int qe)
{
    PII ans = GETMINMAX(0, n - 1, 0, qs, qe, st, ans);
    return ans;
}
void UPDATE(int ss, int se, int si, int index, int new_val, PII *st)
{
    if (index < ss || index > se)
    {
        return;
    }
    if (ss == se)
    {
        st[si].first = st[si].second = new_val;
        return;
    }
    int mid = getMid(ss, se);
    UPDATE(ss, mid, 2 * si + 1, index, new_val, st);
    UPDATE(mid + 1, se, 2 * si + 2, index, new_val, st);
    st[si].first = min(st[si * 2 + 1].first, st[si * 2 + 2].first);
    st[si].second = max(st[si * 2 + 1].second, st[si * 2 + 2].second);
    return;
}
void updateValue(int *arr, PII *st, int n, int index, int new_val)
{
    if (index < 0 || index > n - 1)
    {
        return;
    }
    arr[index] = new_val;
    UPDATE(0, n - 1, 0, index, new_val, st);
}