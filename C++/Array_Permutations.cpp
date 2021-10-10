#include<bits/stdc++.h>
int N, f = 0;
using namespace std;

void permute(vector <int> &v, int i)
{
    if (i == N)
    {
        for (int k = 0 ; k < N ; k++)
        {
            cout << v[k] << " ";
        }
        cout << "\n";
    }
    for (int j = i ; j < N ; j++)
    {
        swap(v[i], v[j]);

        permute(v, i + 1);

        swap(v[i], v[j]);
    }
}
int main()
{

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int i, j, x;
    cin >> N;
    vector <int> v;
    for (i = 0 ; i < N ; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    int start = clock();
    permute(v, 0);
    int stop = clock();
    cout << "Execution time: " << fixed << double(stop - start) / double(CLOCKS_PER_SEC) << "sec" << setprecision(5);
}

