#include<bits/stdc++.h>
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define pi pair<int, int>
#define umap unordered_map<int, int>
#define MOD7 1000000007
using namespace std;

int main()
{
    SPEED;
    string s, t, newStr = "";
    cin >> s >> t;
    int l, r, start = 0, end = 0;
    unordered_map<char, int> u;
    unordered_map<char, int> u1;
    for (int i = 0 ; i < t.length() ; i++)
    {
        u.insert(mp(t[i], 0));
    }
    for (int i = 0 ; i < t.length() ; i++)
    {
        u1[t[i]]++;
    }
    int missing = t.length();
    int res = INT_MAX, minimum = 0;
    l = 0;
    r = 0;
    while (r < s.length())
    {
        if (u.find(s[r]) != u.end())
        {
            if (u[s[r]] == 0 || u1[s[r]] > u[s[r]])
            {
                u[s[r]]++;
                missing--;
            }
            else
            {
                u[s[r]]++;
            }
        }
        while (missing == 0)
        {
            minimum = r - l + 1;
            if (res > minimum)
            {
                res = minimum;
                start = l;
                end = r;
            }
            if (u.find(s[l]) != u.end())
            {
                u[s[l]]--;
                if (u[s[l]] == 0 || u[s[l]] < u1[s[l]])
                {
                    missing++;
                }
            }
            l++;
        }
        r++;
    }
    if (res == INT_MAX)
        cout << "No such string" << "\n";
    else
    {
        newStr = s.substr(start, res);
        cout << newStr << "\n";
        cout << "Starting Index = " << start << "\n";
        cout << "Ending Index = " << end << "\n";
    }
    return 0;
}