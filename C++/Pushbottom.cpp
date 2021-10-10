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
void pushBottom(int x, stack<int> &s)
{
	if (s.empty())
	{
		s.push(x);
		return;
	}
	int y = s.top();
	s.pop();
	pushBottom(x, s);
	s.push(y);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x, y;
	stack <int> s;
	cin >> x;				//Value to be pushed at bottom
	while (cin >> y)		//Stack
	{
		s.push(y);
	}
	pushBottom(x, s);
	showstack(s);
	return 0;
}
