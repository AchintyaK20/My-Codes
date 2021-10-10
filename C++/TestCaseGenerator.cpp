#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    rand();
    int randomNumber;
    int t = 1, n = 200000;
    cout << t << "\n";
    cout << n << "\n";
    for (int index = 0; index < 200000; index++)
    {
        randomNumber = (rand() % 200000) + 1;
        cout << randomNumber << " ";
    }
    cout << endl;
}