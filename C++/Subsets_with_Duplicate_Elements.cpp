#include <bits/stdc++.h>
using namespace std;

// Function to print the elements of a vector
void printVector(vector<int> const &out)
{
	for (int i: out)
		cout << i << " ";
	cout << '\n';
}

// Recursive function to print all distinct subsets of S
// S	--> input set
// out  --> vector to store subset
// i	--> index of next element in set S to be processed
void findPowerSet(vector<int> &S, vector<int> &out, int i)
{
	// if all elements are processed, print the current subset
	if (i == S.size())
	{
		printVector(out);
		return;
	}

	// include current element in the current subset and recur
	out.push_back(S[i]);
	findPowerSet(S, out, i + 1);

	// exclude current element in the current subset
	out.pop_back(); // backtrack

	// remove adjacent duplicate elements
	while (i < S.size() - 1 && S[i] == S[i + 1])
		i++;

	// exclude current element in the current subset and recur
	findPowerSet(S, out, i + 1);
}

// Program to generate all distinct subsets of given set
int main()
{
	int n;
	cin >> n;
	vector<int> S(n);
	for (int i = 0; i<n; i++)
	{
		cin >> S[i];
	}
	// sort the set
	sort(S.begin(), S.end());

	// create an empty vector to store elements of a subset
	vector<int> out;
	findPowerSet(S, out, 0);

	return 0;
}