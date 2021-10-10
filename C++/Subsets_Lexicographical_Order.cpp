#include<bits/stdc++.h>
using namespace std;
int n;

void lexi(int *temp, int size, int i, int *arr)
{
	int k, j;
	for (k = 0 ; k < size ; k++)
	{
		cout << temp[k] << " ";
	}
	cout << "\n";
	if (i == n)
	{
		return;
	}
	for (j = i ; j < n ; j++)
	{
		temp[size] = arr[j];
		lexi(temp, size + 1, j + 1, arr);
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i, j, size, temp[100];
	cin >> n;
	int arr[n];
	for (i = 0 ; i < n ; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	lexi(temp, 0, 0, arr);

}