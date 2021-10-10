// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    //taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        //taking size of array
        cin >> n;
        int a[n];

        //inserting elements to the array
        for (int i = 0;i < n;i++)
            cin >> a[i];

        //calling method longestSubsequence()
        cout << longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends


// return length of longest strictly increasing subsequence

int CEIL(int mini[], int low, int high, int key)
{
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (mini[mid] >= key)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}
int longestSubsequence(int n, int a[])
{
    int mini[n];
    mini[0] = a[0];
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > mini[len - 1])
        {
            mini[len] = a[i];
            len++;
        }
        else
        {
            int x = CEIL(mini, 0, len - 1, a[i]);
            mini[x] = a[i];
        }
    }
    return len;
}
