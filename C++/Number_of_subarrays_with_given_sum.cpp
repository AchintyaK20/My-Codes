// { Driver Code Starts
#include <iostream>
using namespace std;

int subArraySum(int arr[], int n, int sum);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, sum = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> sum;
        cout << subArraySum(arr, n, sum) << endl;
    }
    return 0;
}  // } Driver Code Ends

int subArraySum(int arr[], int n, int sum) {
    unordered_map<int, int> u;
    int res = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        curr += arr[i];
        if (curr == sum)
            res++;
        if (u.find(curr - sum) != u.end()) {
            res += u[curr - sum];
        }
        u[curr]++;
    }
    return res;
}