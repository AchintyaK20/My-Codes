#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t, final = 0;
    cin >> t;
    while (t--)
    {
        int movie[4][4];
        memset(movie, 0, sizeof(movie));
        int req , result = -100000;
        cin >> req;
        for (int i = 0; i < req; i++)
        {
            string m;
            int time;
            cin >> m;
            cin >> time;

            if (m == "A" && time == 12) movie[0][0]++;
            else if (m == "A" && time == 3) movie[0][1]++;
            else if (m == "A" && time == 6) movie[0][2]++;
            else if (m == "A" && time == 9) movie[0][3]++;
            else if (m == "B" && time == 12) movie[1][0]++;
            else if (m == "B" && time == 3) movie[1][1]++;
            else if (m == "B" && time == 6) movie[1][2]++;
            else if (m == "B" && time == 9) movie[1][3]++;
            else if (m == "C" && time == 12) movie[2][0]++;
            else if (m == "C" && time == 3) movie[2][1]++;
            else if (m == "C" && time == 6) movie[2][2]++;
            else if (m == "C" && time == 9) movie[2][3]++;
            else if (m == "D" && time == 12) movie[3][0]++;
            else if (m == "D" && time == 3) movie[3][1]++;
            else if (m == "D" && time == 6) movie[3][2]++;
            else if (m == "D" && time == 9) movie[3][3]++;
        }


        //long long int max = 0;
        int A, B, C, D;
        for (int k = 0; k < 4; k++)
        {
            vector <int> v;
            v.push_back(movie[0][k]);
            for (int i = 0; i < 4; i++)
            {
                if (i == k ) v.push_back(0);
                else v.push_back(movie[1][i]);
                for (int j = 0; j < 4; j++)
                {
                    if (i == j || j == k ) v.push_back(0);
                    else v.push_back(movie[2][j]);
                    for (int l = 0; l < 4 ; l++)
                    {
                        if (l == j || l == k || l == i ) v.push_back(0);
                        else v.push_back(movie[3][l]);
                        int z = count(v.begin(), v.end(), 0);
                        vector <int>ass;
                        ass = v;
                        sort(ass.begin(), ass.end(), greater<int>());
                        result = max(result, ((ass[0] * 100) + (ass[1] * 75 ) + (ass[2] * 50) + (ass[3] * 25)) - (z * 100) );
                        v.pop_back();
                    }
                    v.pop_back();
                }
                v.pop_back();
            }
            v.pop_back();

        }
        final += result;
        std::cout << result << std::endl;


    }
    cout << final;
    return 0;

}
