// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

bool SolveSudoku(int grid[N][N]);

void printGrid(int grid[N][N]);

int main()
{
    int grid[N][N];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> grid[i][j];
        }
    }
    if (SolveSudoku(grid) == true)
    {
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists";
    }
    return 0;
}

bool isSafe(int i, int j, int n, int grid[N][N])
{
    for (int k = 0; k < N; k++)
    {
        if (grid[i][k] == n || grid[k][j] == n)
        {
            return false;
        }
    }
    int s = sqrt(N);
    int rs = i - i % s;
    int cs = j - j % s;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (grid[i + rs][j + cs] == n)
            {
                return false;
            }
        }
    }
    return true;
}
bool SolveSudoku(int grid[N][N])
{
    int i, j, x = -1, y = -1;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                x = i;
                y = j;
                break;
            }
        }
    }
    if (x == -1 and y == -1)
    {
        return true;
    }
    for (int n = 1; n <= N; n++)
    {
        if (isSafe(x, y, n, grid))
        {
            grid[x][y] = n;
            if (SolveSudoku(grid))
            {
                return true;
            }
            grid[x][y] = UNASSIGNED;
        }
    }
    return false;
}

void printGrid(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
