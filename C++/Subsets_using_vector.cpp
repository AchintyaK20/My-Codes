#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int n, a[MAX];

void pass(vector< int > &v , int i)
{
    if (i == n)
    {
        for (int j = 0 ; j < v.size() ; j++)
        {
            cout << v[j] << " ";
        }
        cout << "\n";
        return;
    }
    v.push_back(a[i]);
//	cout<<i<<"\n";
    pass(v, i + 1);
//	cout<<i<<"\n";
    v.pop_back();
//	cout<<i<<endl;
    pass(v, i + 1);
//	cout<<i<<endl;
}
int main()
{
    int i;
    cin >> n;
    for (i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    vector< int > v;
    pass(v, 0);
}