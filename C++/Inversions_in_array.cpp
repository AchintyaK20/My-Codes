// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

long long countInv(long long a[], long long l, long long m, long long r)
{
	long long n1 = m - l + 1, i, j, k;
	long long n2 = r - m;
	long long left[n1], right[n2];
	for (int i = 0 ; i < n1 ; i++)
	{
		left[i] = a[l + i];
	}
	for (int j = 0 ; j < n2 ; j++)
	{
		right[j]  = a[m + 1 + j];
	}
	i = 0; j = 0; k = l;
	long long res = 0;
	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
			res += (n1 - i);
		}
		k++;
	}
	while (i < n1)
	{
		a[k++] = left[i++];
	}
	while (j < n2)
	{
		a[k++] = right[j++];
	}
	return res;
}
long long inversion(long long a[], long long l, long long r)
{
	long long res = 0;
	if (l < r)
	{
		long long m = l + (r - l) / 2;
		res += inversion(a, l, m);
		res += inversion(a, m + 1, r);
		res += countInv(a, l, m, r);
	}
	return res;
}
long long int inversionCount(long long a[], long long n)
{
	long long inversionC = inversion(a, 0, n - 1);
	return inversionC;
}


// { Driver Code Starts.

int main() {

	long long T;
	cin >> T;

	while (T--) {
		long long N;
		cin >> N;

		long long A[N];
		for (long long i = 0; i < N; i++) {
			cin >> A[i];
		}

		cout << inversionCount(A, N) << endl;
	}

	return 0;
}
// } Driver Code Ends