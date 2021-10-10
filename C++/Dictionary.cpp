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

void printLexi(string s, int cnt)
{
	if (cnt < 0 || s.length() >=3)
	{
		return;
	}
	if (s != "")
	{
		cout << s << "\n";
		cnt--;
	}
	printLexi(s + 'a', cnt);
	printLexi(s + 'b', cnt);
	printLexi(s + 'c', cnt);
}
int main()
{
	SPEED;
	string s = "";
	int n;
	cin >> n;
	printLexi(s, n);
	return 0;
}