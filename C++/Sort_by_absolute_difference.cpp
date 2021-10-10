// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


class compare {
private:
	int num;

public:
	compare(int n)
	{
		num = n;
	}

	// Overloads () operator to perform
	// the desired comparison
	int operator()(int arr_num1, int arr_num2)
	{
		return abs(num - arr_num1) < abs(num - arr_num2);
	}
};

void sortABS(int a[], int n, int k)
{
	stable_sort(a, a + n, compare(k));
}


// { Driver Code Starts.

int main()
{
	int T;
	cin >> T;

	while (T--)
	{

		int N, diff;
		cin >> N >> diff;
		int A[N];

		for (int i = 0; i < N; i++)
			cin >> A[i];

		sortABS(A, N, diff);

		for (int & val : A)
			cout << val << " ";
		cout << endl;

	}

	return 0;
}  // } Driver Code Ends