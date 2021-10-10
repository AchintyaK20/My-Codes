#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int firstMissingPositive(vector<int>& nums)
{
    int n = nums.size();
    int free = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] <= 0)
        {
            swap(nums[i], nums[free]);
            free--;
        }
    }
    int size = free + 1;
    for (int i = 0; i < size; i++)
    {
        if (abs(nums[i]) - 1 < size && nums[abs(nums[i]) - 1] > 0)
        {
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (nums[i] > 0)
        {
            return i + 1;
        }
    }
    return size + 1;
}

int main()
{
    SPEED;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << firstMissingPositive(nums);
    return 0;
}