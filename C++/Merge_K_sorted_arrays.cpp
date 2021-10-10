// { Driver Code Starts
#include<bits/stdc++.h>


#define N 105
using namespace std;

int *mergeKArrays(int arr[][N], int k);

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		int arr[N][N];
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++)
			{
				cin >> arr[i][j];
			}
		}
		int *output = mergeKArrays(arr, k);
		printArray(output, k * k);
		cout << endl;
	}
	return 0;
}// } Driver Code Ends


// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
typedef pair<int, pair<int, int> > ppi;
int *mergeKArrays(int arr[][N], int k)
{
	int n = k * k;
	int *res = new int[n];
	priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
	for (int i = 0 ; i < k ; i++)
	{
		pq.push({arr[i][0], {i, 0}});
	}
	int idx = 0;
	while (!pq.empty())
	{
		int ele = pq.top().first;
		int apos = pq.top().second.first;
		int index = pq.top().second.second;
		pq.pop();
		res[idx++] = ele;
		if (index + 1 < k)
		{
			pq.push({arr[apos][index + 1], {apos, index + 1}});
		}
	}
	return res;
}