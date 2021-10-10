#include "bits/stdc++.h"
#define FAST_IO              \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define REP(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define endl "\n"
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define MOD 1000000007
using namespace std;

const int MAX_N = 1e5 + 5;
int R, C, a[MAX_N];

void printSpiral(vector<vector<int>> &vec)
{
	int top = 0, bottom = R - 1, right = C - 1, left = 0;
	while (top <= bottom && left <= right)
	{
		for (int i = left; i <= right; i++)
		{
			cout << vec[top][i] << " ";
		}
		top++;
		for (int i = top; i <= bottom; i++)
		{
			cout << vec[i][right] << " ";
		}
		right--;
		if (top <= bottom)
		{
			for (int i = right; i >= left; i--)
			{
				cout << vec[bottom][i] << " ";
			}
			bottom--;
		}
		if (left <= right)
		{
			for (int i = bottom; i >= top; i--)
			{
				cout << vec[i][left] << " ";
			}
			left++;
		}
	}
}
int main()
{
	FAST_IO;
	int i, k, j;
	cin >> R >> C;
	vector<vector<int>> vec(R, vector<int>(C));

	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			cin >> vec[i][j];
		}
	}
	printSpiral(vec);
	return 0;
}