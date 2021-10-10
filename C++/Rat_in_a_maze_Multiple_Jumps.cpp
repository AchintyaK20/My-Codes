// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void print(int n, vector<int> sol[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int n, vector<int> maze[]);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> maze[n];
        for (int i = 0; i < n; i++)
        {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }

        solve(n, maze);
    }
    return 0;
}
// } Driver Code Ends

bool isSafe(int row, int col, vector<int> maze[], int n)
{
    return (row < n && col < n && maze[row][col] != 0);
}
bool Rat(int x, int y, vector<int> maze[], vector<int> sol[], int n)
{
    if (x == n - 1 && y == n - 1)
    {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(x, y, maze, n))
    {
        sol[x][y] = 1;
        for (int i = 1 ; i <= maze[x][y] && i < n ; i++)
        {
            if (Rat(x, y + i, maze, sol, n))
            {
                return true;
            }
            if (Rat(x + i, y, maze, sol, n))
            {
                return true;
            }
        }
        sol[x][y] = 0;
        return false;
    }
    return false;
}
void solve(int N, vector<int> maze[])
{
    vector<int> sol[N];
    for (int i = 0 ; i < N ; i++)
    {
        for (int j = 0 ; j < N ; j++)
        {
            sol[i].push_back(0);
        }
    }
    if (Rat(0, 0, maze, sol, N))
    {
        print(N, sol);
    }
    else
    {
        cout << "-1" << endl;
    }

    // write code here
}