/*Kth smallest element on unsorted array*/

#include <bits/stdc++.h>
using namespace std;

int fun(int m, int n, int a[]);

int fun(int m, int n, int a[])
{
  int c = 0;
  for (int i = 0 ; i < n ; i++)
  {
    if (a[i] <= m)
    {
      c++;
    }
  }
  return c;
}
int main()
{
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n, l, h, mid, c, i, k;
  cin >> n;
  int a[n];
  for (i = 0 ; i < n ; i++)
  {
    cin >> a[i];
  }
  cin >> k;
  l = *min_element(a, a + n) - 1;
  h = *max_element(a, a + n);
  while (h - l > 1)
  {
    mid = (l + h) / 2;
    c = fun(mid, n, a);
    if (c >= k)
    {
      h = mid;
    }
    else
    {
      l = mid;
    }
  }
  cout << h;
  return 0;
}