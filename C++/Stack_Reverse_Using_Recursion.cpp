#include<bits/stdc++.h>
using namespace std;

void pushBottom(int y, stack<int> &s);

void showstack(stack <int> &s)
{
	while (!s.empty())
	{
		cout << s.top() << "\n";
		s.pop();
	}
	cout << '\n';
}
void reverse(stack <int> &s)
{
	if (!s.empty())
	{
		return;
	}
	int y = s.top();
	s.pop();
	reverse(s);
	pushBottom(y, s);

}
void pushBottom(int y, stack <int> &s)
{
	stack <int> temp;
	while (!s.empty())
	{
		temp.push(s.top());
		s.pop();
	}
	s.push(y);
	while (!temp.empty())
	{
		s.push(temp.top());
		temp.pop();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	stack <int> s;
	int x;
	while (cin >> x)
	{
		s.push(x);
	}
	reverse(s);
	showstack(s);
	return 0;
}