#include "bits/stdc++.h"
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define MP make_pair
#define PB push_back
#define vi vector<int>
#define pi pair<int, int>
#define REP(i,a,b) for (int i = a; i < b; i++)
#define F first
#define S second
#define endl "\n"
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define MOD7 1000000007
using namespace std;

int towerOfHanoi(int n, string Source, string Auxiliary, string Destination, int moves)
{
    if (n == 1)
    {
        cout << "Move 1 from " << Source << " --> " << Destination << endl;
        return 1 + moves;
    }
    moves = towerOfHanoi(n - 1, Source, Destination, Auxiliary, moves);
    cout << "Move " << n << " from " << Source << " --> " << Destination << endl;
    moves++;
    moves = towerOfHanoi(n - 1, Auxiliary, Source, Destination, moves);
    return moves;
}
int main()
{
    FAST_IO;
    int n;
    cin >> n;
    string Source = "A";
    string Destination = "C";
    string Auxiliary = "B";
    int moves = towerOfHanoi(n, Source, Auxiliary, Destination, 0);
    cout << moves;
    return 0;
}