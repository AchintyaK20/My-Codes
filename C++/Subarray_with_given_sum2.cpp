// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Function to find the subarray with given sum k
// arr: input array
// n: size of array
void subarraySum(int a[], int n, int s)
{
    int l = 0, r = 0;
    int cur = 0, f = 0;
    while (r < n)
    {
        cur += a[r];
        r++;
        while (cur > s && l < r)
        {
            cur -= a[l];
            l++;
        }
        if (cur == s)
        {
            f = 1;
            cout << l + 1 << " " << r;
            break;
        }
    }
    if (f == 0)
    {
        cout << "-1";
    }

}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        subarraySum(arr, n, s);
        cout << endl;

    }
    return 0;
}  // } Driver Code Ends