#include<bits/stdc++.h>
#define MAX 100

using namespace std;
int n,a[MAX],SUM;

int SS(int CS,int i)
{
	if(i==n)
	{
		if(CS==0)
		{
			return 1;
		}
		else 
		{
			return 0;
		}
	}
	int sum=0,k;
	for(k=0 ; k<=SUM/a[i] ; k++)
	{
		sum = sum + SS(CS-a[i]*k, i+1);
	}
	return sum;
}
int main()
{
	int i,CS=0;
	cin>>n;
	for(i=0 ; i<n ; i++)
	{
		cin>>a[i];
	}
	cin>>SUM;
	CS = SUM;
	cout<<SS(CS,0);
}