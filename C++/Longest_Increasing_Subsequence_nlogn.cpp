#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int lis(int arr[], int n)
{
    vector<int> tail;
    tail.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > tail.back())
        {
            tail.push_back(arr[i]);
        }
        else
        {
            int idx = lower_bound(tail.begin(), tail.end(), arr[i]) - tail.begin();
            tail[idx] = arr[i];
        }
    }
    return tail.size();
}
int main()
{
    SPEED;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << lis(arr, n);
    return 0;
}