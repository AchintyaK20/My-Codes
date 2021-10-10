#include "bits/stdc++.h"
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define mp make_pair
#define pb push_back
#define p pair
#define vt vector
#define F first
#define S second
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define endl "\n"
#define CEIL(a,b) ceil((float)(a)/(b))
#define db(v) for(auto &x : v) cout << x << " ";
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
using namespace std;

void heapify(int arr[], int n, int i)
{
	int largest = i, left = 2 * i + 1, right = 2 * i + 2;
	if (left < n && arr[largest] < arr[left])
	{
		largest = left;
	}
	if (right < n && arr[largest] < arr[right])
	{
		largest = right;
	}
	if (largest != i)
	{
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);
	}
}
void buildHeap(int arr[], int n)
{
	for (int i = (n - 2) / 2 ; i >= 0 ; i--)
	{
		heapify(arr, n, i);
	}
}

void heapSort(int arr[], int n)
{
	buildHeap(arr, n);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}


/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	int n, i;
	cin >> n;
	int arr[n];
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	//db(arr);
	heapSort(arr, n);
	printArray(arr, n);
	return 0;
}
