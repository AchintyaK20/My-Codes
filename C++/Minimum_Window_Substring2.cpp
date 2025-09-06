// { Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

// return the smallest window in S with all the characters of P
// if no such window exists, return "-1"
string smallestWindow(string S, string P) {
    int n = S.length(), m = P.length();
    int freq[26] = {0};
    int occ[26];
    memset(occ, -1, sizeof(occ));
    for (int i = 0; i < m; i++) {
        freq[P[i] - 'a']++;
        occ[P[i] - 'a'] = 0;
    }

    int l = 0, r = 0;
    int missing = P.length(), res = INT_MAX;
    int minimum = 0, start = 0, end = 0;
    string newStr = "";
    while (r < n) {
        if (occ[S[r] - 'a'] != -1) {
            if (freq[S[r] - 'a'] > occ[S[r] - 'a']) {
                occ[S[r] - 'a']++;
                missing--;
            } else {
                occ[S[r] - 'a']++;
            }
        }
        while (missing == 0) {
            minimum = r - l + 1;
            if (res > minimum) {
                res = minimum;
                start = l;
                end = r;
            }
            if (occ[S[l] - 'a'] != -1) {
                occ[S[l] - 'a']--;
                if (occ[S[l] - 'a'] < freq[S[l] - 'a']) {
                    missing++;
                }
            }
            l++;
        }
        r++;
    }
    if (res == INT_MAX) {
        return "-1";
    } else {
        newStr = S.substr(start, res);
        return newStr;
    }
}

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string pat;
        cin >> pat;

        cout << smallestWindow(s, pat) << endl;
    }
    return 0;
}  // } Driver Code Ends