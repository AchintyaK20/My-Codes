// { Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

bool myCmp(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.second < p2.second;
}
int activitySelection(int start[], int end[], int n)
{
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = make_pair(start[i], end[i]);
    }
    sort(a, a + n, myCmp);
    for (int i = 0 ; i < n ; i++)
    {
        cout << a[i].first << " " << a[i].second << endl;
    }
    int c = 1;
    int prev = 0;
    for (int curr = 1; curr < n; curr++)
    {
        if (a[curr].first >= a[prev].second)
        {
            c++;
            prev = curr;
        }
    }
    return c;
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
        int start[n], end[n];

        for (int i = 0; i < n; i++)
            cin >> start[i];
        for (int i = 0; i < n; i++)
            cin >> end[i];

        cout << activitySelection(start, end, n) << endl;
    }
    return 0;
}
// } Driver Code Ends