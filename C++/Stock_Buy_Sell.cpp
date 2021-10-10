#include <bits/stdc++.h>
using namespace std;

// solution structure
struct Interval
{
    int buy;
    int sell;
};

// } Driver Code Ends

// solution structure
/* struct Interval
 {
     int buy;
     int sell;
 };*/

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n)
{
    int i = 0, c = 0;
    while (i < n - 1)
    {
        while ((i < n - 1) && (price[i + 1] <= price[i]))
        {
            i++;
        }
        if (i == n - 1 && c != 1)
        {
            cout << "No Profit";
            return;
        }
        int buy = i++;
        while ((i < n) && (price[i] >= price[i - 1]))
        {
            i++;
        }
        int sell = i - 1;
        if (buy == sell)
            return;
        cout << "("
             << buy
             << " " << sell << ")"
             << " ";
        c = 1;
    }
}

// { Driver Code Starts.

// Driver program to test above functions
int main()
{

    int price[10000], n, i, T;

    scanf("%d", &T);

    while (T--)
    {

        scanf("%d", &n);

        for (i = 0; i < n; i++)
            scanf("%d", &price[i]);
        // fucntion call
        stockBuySell(price, n);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends