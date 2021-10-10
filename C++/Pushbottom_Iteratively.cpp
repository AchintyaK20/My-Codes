#include<bits/stdc++.h>
using namespace std;

void showstack(stack <int> &s)
{
	while (!s.empty())
	{
		cout << s.top() << "\n";
		s.pop();
	}
	cout << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x,y;
	stack <int> s,temp;
	cin >> x;				//Value to be pushed at bottom
	while (cin >> y)		//Stack
	{
		s.push(y);
	}
	while(!s.empty())
	{
		temp.push(s.top());
		s.pop();
	}
	s.push(x);
	while(!temp.empty())
	{
		s.push(temp.top());
		temp.pop();
	}
	showstack(s);
	return 0;
}