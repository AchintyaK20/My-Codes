// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> sortByFreq(int arr[], int n);

int main() {


	int t;
	cin >> t;


	while (t--) {


		int n;
		cin >> n;

		int a[n + 1];

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> v;
		v = sortByFreq(a, n);
		for (int i : v)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}

// } Driver Code Ends


//Complete this function
//Return the sorted array
bool comp(pair<int, pair<int, int>> &p, pair<int, pair<int, int>> &p1)
{
	if (p.second.second != p1.second.second)
	{
		return (p.second.second > p1.second.second);
	}
	else
	{
		return (p.second.first < p1.second.first);
	}
}
vector<int> sortByFreq(int arr[], int n)
{
	sort(arr, arr + n);
	unordered_map<int, pair<int, int>> u;
	for (int i = 0 ; i < n ; i++)
	{
		if (u.find(arr[i]) != u.end())
		{
			u[arr[i]].second++;
		}
		else
		{
			u[arr[i]] = make_pair(i, 1);
		}
	}
	vector < pair<int, pair<int, int>>> vec;
	for (auto x : u)
	{
		vec.push_back(make_pair(x.first, x.second));
	}
	sort(vec.begin(), vec.end(), comp);
	vector<int> v;
	for (int i = 0 ; i < vec.size() ; i++)
	{
		int freq = vec[i].second.second;
		while (freq--)
		{
			v.push_back(vec[i].first);
		}
	}
	return v;
}