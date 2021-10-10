// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n)
{
	unordered_set<int> sumSet;

	// Traverse through array and store prefix sums
	int sum = 0;
	for (int i = 0 ; i < n ; i++)
	{
		sum += arr[i];

		// If prefix sum is 0 or it is already present
		if (sum == 0 || sumSet.find(sum) != sumSet.end())
			return true;

		sumSet.insert(sum);
	}
	return false;
}

// Driver code
int main()
{
	int i, h, l, m, key, n;
	cin >> n;
	int arr[n];
	for (i = 0 ; i < n ; i++)
	{
		cin >> arr[i];
	}
	if (subArrayExists(arr, n))
		cout << "Found a subarray with 0 sum";
	else
		cout << "No Such Sub Array Exists!";
	return 0;
}
