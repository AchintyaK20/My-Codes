#include<bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define F first
#define S second
#define endl "\n"
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define MOD7 1000000007
using namespace std;

vi v1,v2;
bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
  	for (int i = 2; i <= sqrt(n); i++) 
    {
        if (n % i == 0) 
        {
            return false; 
        }
    }
  	return true; 
} 
void concatenate(int a, int b)
{
	string s1 = to_string(a);
	string s2 = to_string(b);
	string s = s1 + s2;
	int c = stoi(s);
	if(isPrime(c))
	{
		v2.pb(c);
	}
}
int main()
{
	FAST_IO;
	int n1, n2,j;
	cin >> n1 >> n2;
	vi v;
	int i,flag;
	while (n1 < n2)
	{
		flag = 0;
		for (i = 2; i <= sqrt(n1) ; ++i)
		{
			if (n1 % i == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			v.pb(n1);
		++n1;
	}
	for(i=0 ; i<v.size() ; i++)
	{
		for(j=0 ; j<v.size() ; j++)
		{
			if(i == j)
				continue;
			else
				concatenate(v[i],v[j]);
		}
	}
	vector<int>::iterator ip2;
	sort(v2.begin(), v2.end());
	ip2 = unique(v2.begin(), v2.end());
	v2.resize(distance(v2.begin(), ip2));

	ll first = v2[0];
	ll second = v2[v2.size() - 1];
	ll temp;
	for (i = 2; i < v2.size(); i++)
	{
		temp = first + second;
		first = second;
		second = temp;
	}

	cout<< second;
	return 0;
}