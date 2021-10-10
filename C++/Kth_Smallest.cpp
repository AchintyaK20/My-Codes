// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
int Partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for(int j = l ; j<r ; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

int kthSmallest(int arr[], int n, int k)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int p = Partition(arr, l, r);
        if (p == k - 1)
        {
            return arr[p];
        }
        else if (p > k - 1)
        {
            r = p - 1;
        }
        else
        {
            l = p + 1;
        }
    }
}

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {

        int n, k;
        cin >> n >> k;
        int arr[n];

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        cout << kthSmallest(arr, n, k) << endl;

    }
    return 0;
}  // } Driver Code Ends