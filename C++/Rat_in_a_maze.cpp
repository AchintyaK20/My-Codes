// { Driver Code Starts
#include <iostream>

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
            for (int j = 0; j < n; j++)
                cin >> maze[i][j];
        }

        solve(n, maze);
    }
    return 0;
}
// } Driver Code Ends

//Function to find the minimum number of Hops required for the rat to
//reach from the source block to the destination block.
bool isSafe(int i, int j, int N, vector<int> maze[])
{
    return (i < N && j < N && maze[i][j] != 0);
}

bool solveRec(int i, int j, int N, vector<int> maze[], vector<int> sol[])
{
    if (i == N - 1 && j == N - 1 && maze[i][j] != 0)
    {
        sol[i][j] = 1;
        return true;
    }
    if (isSafe(i, j, N, maze))
    {
    	sol[i][j] = 1;
        for (int k = 1; k <= maze[i][j]; k++)
        {
        	if (solveRec(i, j + k, N, maze, sol))
        	{
        		return true;
        	}
        	if (solveRec(i + k, j, N, maze, sol))
        	{
        		return true;
        	}
        }
        sol[i][j] = 0;
    }
    return false;
}
void solve(int N, vector<int> maze[])
{
    vector<int> sol[N];
    for (int i = 0; i < N; i++)
    {
        sol[i] = vector<int>(N, 0);
    }
    if (solveRec(0, 0, N, maze, sol))
    {
        print(N, sol);
    }
    else
    {
        cout << "-1" << endl;
    }
}