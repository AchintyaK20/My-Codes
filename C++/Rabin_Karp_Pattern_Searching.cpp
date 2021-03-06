// { Driver Code Starts
//Initial Template for C++

/* Following program is a C implementation of
Rabin Karp. Algorithm given in the CLRS book */
#include<bits/stdc++.h>

using namespace std;

bool search(string, string, int);


// } Driver Code Ends


//User function Template for C++

// d is the number of characters in the input alphabet
#define d 256

/* pat -> pattern
    txt -> text
    q -> A prime number
*/
bool search(string pat, string txt, int q)
{
    long long h = 1;
    int n = txt.length(), m = pat.length();
    for (int i = 1 ; i <= m - 1 ; i++)
    {
        h = (h * d) % q;
    }
    long long p = 0, t = 0;
    for (int i = 0 ; i < m ; i++)
    {
        p = (p * d + pat[i]) % q;
        t = (t * d + txt[i]) % q;
    }
    for (int i = 0 ; i <= n - m ; i++)
    {
        if (p == t)
        {
            bool flag = true;
            for (int j = 0 ; j < m ; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return true;
            }
        }
        if (i < n - m)
        {
            t = ((d * (t - txt[i] * h)) + txt[i + m]) % q;
            if (t < 0)
            {
                t = t + q;
            }
        }
    }
    return false;
}

// { Driver Code Starts.

/* Driver program to test above function */
int main()
{
    int t;
    cin >> t;

    while (t--) {
        string s, p;
        cin >> s >> p;
        int q = 101; // A prime number
        if (search(p, s, q)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
// } Driver Code Ends