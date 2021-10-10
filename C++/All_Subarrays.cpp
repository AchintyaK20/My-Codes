/* C++ code to generate all possible subarrays/subArrays
	Complexity- O(n^3) */
#include<bits/stdc++.h>
using namespace std;

// Prints all subarrays in arr[0..n-1]
void subArray(int arr[],int n);
void subArray(int arr[], int n)
{
	// Pick starting point
	for (int i=0; i <n; i++)
	{
		// Pick ending point
		for (int j=i; j<n; j++)
		{
			// Print subarray between current starting
			// and ending points
			for (int k=i; k<=j; k++)
				cout << arr[k] << " ";

			cout << endl;
		}
	}
}

// Driver program
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int arr[40],i,n;
	cin>>n;
	for(i=0 ; i<n ; i++)
	{
		cin>>arr[i];
	}
	subArray(arr,n);

}
