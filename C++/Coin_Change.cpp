#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//User function Template for C++

//Complete this function
long long dp[1001][1001];
long long ways(int coins[], int n, int value)
{
    if (value == 0)
    {
        return 1;
    }
    if (value < 0 || n == 0)
    {
        return 0;
    }
    if (dp[n][value] != -1)
    {
        return dp[n][value];
    }
    long long include = ways(coins, n, value - coins[n - 1]);
    long long exclude = ways(coins, n - 1, value);
    return dp[n][value] = include + exclude;
}
long long numberOfWays(int coins[], int n, int value)
{
    memset(dp, -1, sizeof(dp));
    return ways(coins, n, value);
}


// { Driver Code Starts.


int main()
{

    //taking total count of testcases
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        //taking value
        int value;
        cin >> value;

        //taking number of coins
        int numberOfCoins;
        cin >> numberOfCoins;
        int coins[numberOfCoins];

        //inserting coins to the array
        for (int i = 0; i < numberOfCoins; i++)
            cin >> coins[i];

        //calling function numberOfWays
        cout << numberOfWays(coins, numberOfCoins, value) << endl;

    }
    return 0;
}  // } Driver Code Ends