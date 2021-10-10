#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main()
{
    SPEED;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // Max Heap contains the first half elements (+1 in case of odd sized array).
    priority_queue<int> maxi;

    // Min Heap contains the second half elements.
    priority_queue<int, vector<int>, greater<int>> mini;

    cout << arr[0] << " ";
    maxi.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        if (maxi.size() <= mini.size())
        {
            if (x < mini.top())
            {
                maxi.push(x);
            }
            else
            {
                int temp = mini.top();
                mini.pop();
                maxi.push(temp);
                mini.push(x);
            }
            cout << maxi.top() << " ";
        }
        else
        {
            if (x >= maxi.top())
            {
                mini.push(x);
            }
            else
            {
                int temp = maxi.top();
                maxi.pop();
                mini.push(temp);
                maxi.push(x);
            }
            cout << (maxi.top() + mini.top()) / 2.0 << " ";
        }
    }
    return 0;
}