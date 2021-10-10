#include<bits/stdc++.h>
#define MAX 100

using namespace std;
int n,SUM,a[MAX];

void SS(int CS,int i,int *temp,int size)
{
	int k,j;
	if(i==n)
	{
		if(CS==0)
		{
			for(k=0 ; k<size ; k++)
			{
				cout<<temp[k];
			}
		}
	}
	for(k=0 ; k<=SUM/a[i] ; k++)
	{
		for(j=0 ; j<k ; j++)
		{
			temp[size+j] = a[i];
		}
		SS(CS-a[i]*k, i+1, temp, size+k);
	}
}
int main()
{
	int i,*temp,CS;
	cin>>n;
	for(i=0 ; i<n ; i++)
	{
		cin>>a[i];
	}
	cin>>SUM;
	CS = SUM;
	SS(CS,0,temp,0);
}