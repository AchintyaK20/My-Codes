// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Function to calculate span
// price[]: price array in input
// n: size of array
vector <int> calculateSpan(int price[], int n)
{
    stack <int> s;
    vector <int> v;
    s.push(0);
    v.push_back(1);
    for (int i = 1 ; i < n ; i++)
    {
        while (!s.empty() && price[i] >= price[s.top()])
        {
            s.pop();
        }
        v.push_back(s.empty() ? i + 1 : i - s.top());
        s.push(i);
    }
    return v;
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
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector <int> s = calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends