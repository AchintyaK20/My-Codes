#include <iostream>
#include <iomanip>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool myCmp(const Item& a, const Item& b)
{
    double d1 = a.value / (double)a.weight;
    double d2 = b.value / (double)b.weight;
    return d1 > d2;
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    double res = 0.0;
    sort(arr, arr + n, myCmp);
    for (int i = 0; i < n; i++)
    {
        if (W >= arr[i].weight)
        {
            W -= arr[i].weight;
            res += arr[i].value;
        }
        else
        {
            res += (W * arr[i].value) / (double)(arr[i].weight);
            break;
        }
    }
    return res;
}

int main()
{
    int t = 1;
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        int n, W;
        cin >> n >> W;

        Item arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }
        cout << fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}