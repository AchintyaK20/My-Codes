// { Driver Code Starts
// C Program for counting sort
#include <stdio.h>
#include <string.h>
#define RANGE 255

// The main function that sort the given string arr[] in
// alphabatical order
char* countSort(char arr[]);

// Driver program to test above function
int main()
{
	long int t;
	scanf("%ld", &t);
	while (t--)
	{
		long int n;
		scanf("%ld", &n);
		char arr[n + 1];
		scanf("%s", arr);
		printf("%s\n", countSort(arr));
	}
	return 0;
}

// } Driver Code Ends


// The main function that sort the given string arr[] in
// alphabatical order
// return the sorted char array
char* countSort(char arr[])
{
	int count[26];
	int n = strlen(arr), i;
	memset(count, 0, sizeof(count));
	for (i = 0 ; i < n ; i++)
	{
		count[arr[i] - 97]++;
	}
	for (i = 1 ; i < 26 ; i++)
	{
		count[i] = count[i - 1] + count[i];
	}
	char output[n];
	for (i = n - 1 ; i >= 0 ; i--)
	{
		output[count[arr[i] - 97] - 1] = arr[i];
		count[arr[i] - 97]--;
	}
	for (i = 0 ; i < n ; i++)
	{
		arr[i] = output[i];
	}
	return arr;
}