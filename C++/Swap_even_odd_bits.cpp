// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

// function to swap odd and even bits
unsigned int swapBits(unsigned int n)
{
	unsigned int even = 0xAAAAAAAA & n; //Get all even bits.
	unsigned int odd = 0x55555555 & n;	//Get all odd bits.
	even = even >> 1;					//Right shift even bits.
	odd = odd << 1;						//Left shift odd bits.
	unsigned ans = even | odd;			//Get the final answer.
	return ans;
}

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		unsigned int n;
		cin >> n;
		cout << swapBits(n) << endl;
	}
	return 0;
} // } Driver Code Ends
