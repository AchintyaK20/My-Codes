// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <iostream>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job
{
    int id;  // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
    static bool myCmp(const Job &a, const Job &b)
    {
        return (a.profit > b.profit);
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, myCmp);
        vector<int> slot(n, -1);
        int ans = 0, jobs = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = min(arr[i].dead, n) - 1; j >= 0; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = arr[i].id;
                    ans += arr[i].profit;
                    jobs++;
                    break;
                }
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        // cout << slot[i] << " ";
        // }
        // cout << endl;
        vector<int> temp{jobs, ans};
        return temp;
    }
};

// { Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;
        Job arr[n];

        //adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends