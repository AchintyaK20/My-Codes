#include<bits/stdc++.h>
using namespace std;

int subString(string s1)
{
	int pos[26];
	int s = 0, e = 0 , ans = 1, i;
	memset(pos, -1, sizeof(pos));
	pos[s1[0] - 'a'] = 0;
	int j = 1;
	while (j < s1.length())
	{
		if (pos[s1[j] - 'a'] == -1)
		{
			pos[s1[j] - 'a'] = j;
			e++;
		}
		else
		{
			int last = pos[s1[j] - 'a'];
			for (i = s ; i <= last ; i++)
			{
				pos[s1[i] - 'a'] = -1;
			}
			s = i;
			e++;
			pos[s1[j] - 'a'] = j;
		}
		j++;
		ans = max(ans, e - s + 1);
	}

	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;
	cout << subString(s);

	return 0;
}