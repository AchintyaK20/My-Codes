// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


void printVector(const vector<int>& a)
{
    for (auto e : a) {
        cout << e << " ";
    }
    cout << endl;
}

// } Driver Code Ends


// Function to merge three sorted arrays
// A, B, and C: input sorted arrays
vector<int> mergeThree(vector<int>& a, vector<int>& b, vector<int>& c)
{
    int n = a.size(), m = b.size(), p = c.size();
    int i = 0, j = 0, k = 0;
    vector<int> v;
    while (i < n && j < m && k < p)
    {
        if (a[i] < b[j])
        {
            if (a[i] < c[k])
            {
                v.push_back(a[i]);
                i++;
            }
            else if (a[i] == c[k])
            {
                v.push_back(a[i]);
                v.push_back(c[k]);
                i++; k++;
            }
            else
            {
                v.push_back(c[k]);
                k++;
            }
        }
        else if (a[i] == b[j])
        {
            if (a[i] == c[k])
            {
                v.push_back(a[i]);
                v.push_back(b[j]);
                v.push_back(c[k]);
                i++; j++; k++;
            }
            else if (a[i] < c[k])
            {
                v.push_back(a[i]);
                v.push_back(b[j]);
                i++; j++;
            }
            else
            {
                v.push_back(c[k]);
                k++;
            }
        }
        else
        {
            if (b[j] < c[k])
            {
                v.push_back(b[j]);
                j++;
            }
            else if (b[i] == c[k])
            {
                v.push_back(b[j]);
                v.push_back(c[k]);
                j++; k++;
            }
            else
            {
                v.push_back(c[k]);
                k++;
            }
        }
    }
    if (i == n)
    {
        while (j < m && k < p)
        {
            if (b[j] < c[k])
            {
                v.push_back(b[j]);
                j++;
            }
            else if (b[j] == c[k])
            {
                v.push_back(b[j]);
                v.push_back(c[k]);
                j++; k++;
            }
            else
            {
                v.push_back(c[k]);
                k++;
            }
        }
        while (j < m)
        {
            v.push_back(b[j]);
            j++;
        }
        while (k < p)
        {
            v.push_back(c[k]);
            k++;
        }
    }
    else if (j == m)
    {
        while (i < n && k < p)
        {
            if (a[i] < c[k])
            {
                v.push_back(a[i]);
                i++;
            }
            else if (a[i] == c[k])
            {
                v.push_back(a[i]);
                v.push_back(c[k]);
                i++; k++;
            }
            else
            {
                v.push_back(c[k]);
                k++;
            }
        }
        while (i < n)
        {
            v.push_back(a[i]);
            i++;
        }
        while (k < p)
        {
            v.push_back(c[k]);
            k++;
        }
    }
    else if (k == p)
    {
        while (i < n && j < m)
        {
            if (a[i] < b[j])
            {
                v.push_back(a[i]);
                i++;
            }
            else if (a[i] == b[j])
            {
                v.push_back(a[i]);
                v.push_back(b[j]);
                i++; j++;
            }
            else
            {
                v.push_back(b[j]);
                j++;
            }
        }
        while (i < n)
        {
            v.push_back(a[i]);
            i++;
        }
        while (j < m)
        {
            v.push_back(b[j]);
            j++;
        }
    }
    return v;
}


// { Driver Code Starts.

int main()
{


    int t;
    cin >> t;
    while (t--) {
        int n, m, o;
        cin >> n >> m >> o;
        vector<int> A, B, C;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            A.push_back(x);
        }

        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            B.push_back(x);
        }

        for (int i = 0; i < o; i++) {
            int x;
            cin >> x;
            C.push_back(x);
        }


        printVector(mergeThree(A, B, C));

    }

    return 0;
}
// } Driver Code Ends