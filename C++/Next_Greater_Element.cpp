#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Function to store Next larger elements


vector <long long> nextLargerElement(long long arr[], int n)
{
    vector<long long> v;
    stack<long long> s;
    s.push(arr[n - 1]);
    v.push_back(-1);
    for (int i = n - 2 ; i >= 0 ; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        v.push_back(s.empty() ? -1 : s.top());
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
    // Your code here
}

// { Driver Code Starts.

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
            cin >> arr[i];


        vector <long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends