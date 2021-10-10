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

void printSub(string str, string curr, int index)
{
	if (index == str.length())
	{
		cout << curr << endl;
		return;
	}
	printSub(str, curr, index + 1);
	printSub(str, curr + str[index], index + 1);
}
int main()
{
	SPEED;
	string str;
	string curr = "";
	int index = 0;
	cin >> str;
	printSub(str, curr, index);
	return 0;
}