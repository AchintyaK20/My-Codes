#include <bits/stdc++.h>
using namespace std;

int dp[1001];
int minJumps(vector<int> &arr, int i, int end)
{
    if (i >= end)
        return dp[i] = 0;
    if (dp[i] != -1)
        return dp[i];
    int min_count = INT_MAX;
    for (int j = 1; j <= arr[i]; j++)
    {
        int count = minJumps(arr, i + j, end);
        if (count != INT_MAX)
        {
            min_count = min(min_count, count + 1);
        }
    }
    return dp[i] = min_count;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << minJumps(arr, 0, n - 1) << endl;
    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    return 0;
}