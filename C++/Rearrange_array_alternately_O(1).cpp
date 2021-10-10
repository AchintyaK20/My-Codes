#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// This function wants you to modify the given input
// array and no need to return anything
// arr: input array
// n: size of array
void rearrange(long long *a, int n)
{
    int i;
    long long max = a[n - 1];
    max = max + 1;
    int even = n-1, odd = 0;
    for(i=0 ; i<n ; i++)
    {
        if(i%2 == 0)
        {
            a[i] = max * (a[even] % max) + a[i];
            even--;
        }
        else
        {
            a[i] = max * (a[odd] % max) + a[i];
            odd++;
        }
    }
    for (i = 0; i < n; i++)
    {
        a[i] = a[i] / max;
    }
}

// { Driver Code Starts.

// Driver program to test above function
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        rearrange(arr, n);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends