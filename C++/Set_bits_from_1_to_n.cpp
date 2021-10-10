#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

// Function to count set bits in the given number x
// n: input to count the number of set bits

int countSetBits(int n)
{
	n = n + 1;
	int powerOf2 = pow(2, 1);
	int count = n / 2;
	while (powerOf2 <= n)
	{
		int pairs = n / powerOf2;
		count += (pairs / 2) * powerOf2;
		count += (pairs & 1) ? (n % powerOf2) : 0;
		powerOf2 = powerOf2 << 1;
	}
	return count;
}

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin >> t;	// input testcases
	while (t--) //while testcases exist
	{
		int n;
		cin >> n; //input n

		cout << countSetBits(n) << endl; // print the answer
	}
	return 0;
}
// } Driver Code Ends