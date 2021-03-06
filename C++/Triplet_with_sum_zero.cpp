// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
bool findTriplets(int arr[], int n);
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
        if(findTriplets(arr, n))
        cout<<"1"<<endl;
        else 
        cout<<"0"<<endl;
	}
    return 0;
}// } Driver Code Ends


/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
bool findTriplets(int a[], int n)
{ 
	sort(a, a+n);
	int i,j,k,idx = 0;
	for(i=0 ; i<n ; i++)
	{
		int l = i+1, r = n-1;
		int x = -a[i];
		while(l<r)
		{
			if(a[l] + a[r] == x)
			{
				return true;
			}
			else if(a[l] + a[r] > x)
			{
				r--;
			}
			else
			{
				l++;
			}
		}
	}
	return false;
}