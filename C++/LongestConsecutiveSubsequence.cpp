// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);

// Driver program
int main()
{
	int  t, n, i, a[100001];
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (i = 0; i < n; i++)
			cin >> a[i];
		cout << findLongestConseqSubseq(a, n) << endl;
	}

	return 0;
}// } Driver Code Ends


// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq(int a[], int n)
{
	unordered_set<int> s;
	for (int i = 0 ; i < n ; i++)
	{
		s.insert(a[i]);
	}
	int ans = 0;
	for (int i = 0 ; i < n ; i++)
	{
		if (s.find(a[i] - 1) == s.end())
		{
			int j = a[i];
			while (s.find(j) != s.end())
			{
				j++;
			}
			ans = max(ans, j - a[i]);
		}
	}
	return ans;
}