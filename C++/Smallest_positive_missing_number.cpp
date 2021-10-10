// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Functio to find first smallest positive
// missing number in the array
int missingNumber(int a[], int n)
{
    int i, shift = 0;
    for (i = 0 ; i < n ; i++)
    {
        if (a[i] <= 0)
        {
            swap(a[i], a[shift]);
            shift++;
        }
    }
    int newSize = n - shift;
    a = a + shift;
    for (i = 0 ; i < newSize ; i++)
    {
        if (abs(a[i]) <= newSize && a[abs(a[i]) - 1] > 0)
        {
            a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];
        }
    }
    for (i = 0 ; i < newSize ; i++)
    {
        if (a[i] > 0)
        {
            return i + 1;
        }
    }
    return newSize + 1;
}

// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)cin >> arr[i];
        cout << missingNumber(arr, n) << endl;
    }
    return 0;
}   // } Driver Code Ends