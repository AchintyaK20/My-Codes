#include <iostream>

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define rep(i,a,b) for (int i = a; i < b; i++)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define endl "\n"
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define MOD 1000000007
using namespace std;

bool matching(char opening, char closing)
{
	return ((opening == '(' && closing == ')') || (opening == '{' && closing == '}') || (opening == '[' && closing == ']'));
}
bool isBalanced(string str)
{
	int n = str.length();
	stack <char> s;
	for (int i = 0 ; i < n ; i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			s.push(str[i]);
		}
		else
		{
			if (s.empty())
			{
				return false;
			}
			else if (matching(s.top(), str[i]) == false)
			{
				return false;
			}
			else
			{
				s.pop();
			}
		}
	}
	return (s.empty() == true);
}
int main()
{
	FAST_IO;
	string str;
	cin >> str;
	cout << isBalanced(str);
	return 0;
}