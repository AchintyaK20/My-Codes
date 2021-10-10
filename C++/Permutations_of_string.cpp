#include<bits/stdc++.h>
#define len(x) (int)x.length()
using namespace std;

void permute(string s, int i)
{
    if (i == len(s))
    {
        cout << s << "\n";
        return;
    }
    for (int j = i; j < len(s); j++)
    {
        swap(s[i], s[j]);
        permute(s, i + 1);
        swap(s[i], s[j]);
    }
}
int main()
{
    string s;
    cin >> s;
    permute(s, 0);
}