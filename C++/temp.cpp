#include <math.h>

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// Check prime
bool isPrime(int n) {
    if (n == 1) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Find prime factors
vector<int> primeFactors(int n) {
    vector<int> result;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            int x = i;
            while (n % x == 0) {
                result.push_back(i);
                x = x * i;
            }
        }
    }
    return result;
}

vector<string> powerSet(string &str) {
    int n = str.size();
    int power = 1 << n;
    vector<string> ans;
    for (int i = 0; i < power; i++) {
        string res = "";
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) {
                res += str[j];
            }
        }
        ans.push_back(res);
    }
    return ans;
}

bool isPalin(string &str, int s, int e) {
    if (s >= e) {
        return true;
    }
    return (str[s] == str[e] && isPalin(str, s + 1, e - 1));
}

int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return n % 10 + sumOfDigits(n / 10);
}

int cuttingRope(int n, int a, int b, int c) {
    if (n == 0) {
        return 0;
    }
    if (n < 0) {
        return -1;
    }
    int res = max(cuttingRope(n - a, a, b, c), max(cuttingRope(n - b, a, b, c), cuttingRope(n - c, a, b, c)));
    if (res == -1) {
        return -1;
    }
    return 1 + res;
}

void tower(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Move 1 from " << A << " to " << C << "\n";
        return;
    }
    tower(n - 1, A, C, B);
    cout << "Move " << n << " from " << A << " to " << C << "\n";
    tower(n - 1, B, A, C);
}

int subsetSum(int sum, int idx, vector<int> &arr) {
    if (sum == 0) {
        return 1;
    }
    if (sum < 0 || idx == arr.size()) {
        return 0;
    }
    return subsetSum(sum - arr[idx], idx + 1, arr) + subsetSum(sum, idx + 1, arr);
}

void permutation(string &s, int i = 0) {
    if (i == s.size() - 1) {
        cout << s << "\n";
        return;
    }
    for (int j = i; j < s.size(); j++) {
        swap(s[i], s[j]);
        permutation(s, i + 1);
        swap(s[i], s[j]);
    }
}

void duplicatesRemove(vector<int> &arr) {
    int n = arr.size();
    int size = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[size - 1]) {
            arr[size] = arr[i];
            size++;
        }
    }
    cout << "Size: " << size << "\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void minFlips(vector<int> &arr) {
    int n = arr.size();
    int oneGroup = 0, zeroGroup = 0;
    for (int i = 0; i < n;) {
        int cur = arr[i];
        cur == 1 ? oneGroup++ : zeroGroup++;
        while (i < n && arr[i] == cur) {
            i++;
        }
    }
    cout << oneGroup << "  " << zeroGroup << endl;
}

vector<int> slidingWindow(vector<int> &arr, int k) {
    int n = arr.size();
    int sumOfFirstK = 0;
    int sum = accumulate(arr.begin(), arr.begin() + k, 0);
    cout << sum << endl;
    return vector<int>{2, 3};
}

void subsets(string &s, string curr = "", int idx = 0) {
    if (idx == s.size()) {
        cout << curr << "\n";
        return;
    }
    subsets(s, curr + s[idx], idx + 1);
    subsets(s, curr, idx + 1);
}

bool subarrySumK(int arr[], int n, int k) {
    int s = 0, e = 0;
    int res = 0;
    int curSum = 0;
    for (e = 0; e < n; e++) {
        curSum += arr[e];
        while (curSum > k) {
            curSum -= arr[s];
            s++;
        }
        if (curSum == k) {
            return true;
        }
    }
    return false;
}

int summation(int s, int e, int arr[]) {
    int sum = 0;
    for (int i = s; i <= e; i++) {
        sum += arr[i];
    }
    return sum;
}

int allocateMinPages(int arr[], int n, int k) {
    if (k == 1) {
        return summation(0, n - 1, arr);
    }
    if (n == 1) {
        return arr[0];
    }
    int res = INT_MAX;
    for (int i = 1; i < n; i++) {
        int perCut = max(allocateMinPages(arr, i, k - 1), summation(i, n - 1, arr));
        res = min(res, perCut);
    }
    return res;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

vector<vector<int>> intervals(vector<vector<int>> &nums) {
    int m = nums.size();
    int n = nums[0].size();
    vector<vector<int>> res;

    sort(nums.begin(), nums.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    });

    res.push_back({nums[0][0], nums[0][1]});
    for (int i = 1; i < m; i++) {
        if (res.back().back() >= nums[i].front()) {
            res.back().front() = min(res.back().front(), nums[i].front());
            res.back().back() = max(res.back().back(), nums[i].back());
        } else {
            res.push_back({nums[i].front(), nums[i].back()});
        }
    }
    return res;
}

int lcs(vector<int> &arr) {
    int n = arr.size();
    unordered_set<int> st(arr.begin(), arr.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (st.count(arr[i] - 1)) {
            continue;
        }
        int sz = 1, curr = arr[i];
        while (st.count(curr + 1)) {
            sz++;
            curr += 1;
        }
        res = max(res, sz);
    }
    return res;
}

// Custom comparator: sort strings by length, then lexicographically
struct CustomCompare {
    bool operator()(const string &a, const string &b) const {
        if (a.length() == b.length())
            return a < b;                // fallback to lexicographical order
        return a.length() < b.length();  // shorter string comes first
    }
};

bool validWordAbbreviation(string word, string abbr) {
    int n = word.size();
    int m = abbr.size();
    int idxToTrack = 0;
    for (int i = 0; i < m;) {
        if (islower(abbr[i])) {
            if (abbr[i] != word[idxToTrack]) {
                return false;
            }
            i++, idxToTrack++;
        } else if (isdigit(abbr[i])) {
            string temp = "";
            while (i < m && isdigit(abbr[i])) {
                temp += abbr[i];
                i++;
            }
            if (temp[0] == '0') {
                return false;
            }
            int num = stoi(temp);
            if (num == 0) {
                return false;
            }
            idxToTrack += num;
        }
    }
    return (idxToTrack == n);
}

void stockSpan(vector<int> &arr) {
    vector<int> span;
    span.push_back(1);
    for (int i = 1; i < arr.size(); i++) {
        int curSpan = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] > arr[j]) {
                curSpan++;
            } else {
                break;
            }
        }
        span.push_back(curSpan);
    }
    for (auto &x : span) {
        cout << x << " ";
    }
}

int lPartition(int arr[], int l, int h) {
    int i = l - 1;
    int pivot = arr[h];
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

int hPartition(int arr[], int l, int h) {
    int i = l - 1;
    int j = h + 1;
    int pivot = arr[l];

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) {
            return i;
        }
        swap(arr[i], arr[j]);
    }
}

int main() {
    vector<int> v = {1, 2, 3};
    v.push_back(4);
    v.pop_back();
    int n = v.size();
    bool empty = v.empty();
    v.clear();
    for (int x : v) { /*...*/
    }
    // Sorting
    sort(v.begin(), v.end());
    sort(v.rbegin(), v.rend());
    sort(v.begin(), v.end(), greater<int>());
    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;
    });
    // Remove element idiom
    v.erase(remove(v.begin(), v.end(), 5), v.end());
    // Lower/upper bound (needs sorted)
    auto it = lower_bound(v.begin(), v.end(), 10);
}
