#include <iostream>
using namespace std;

class SubsequenceChecker {
    vector<vector<int>> nextPos;
    int tLen;

public:
    // Constructor: preprocess t
    SubsequenceChecker(const string& t) {
        tLen = t.size();
        nextPos = vector<vector<int>>(26, vector<int>(tLen + 1, tLen));

        // Fill from right to left
        for (int i = tLen - 1; i >= 0; --i) {
            for (int c = 0; c < 26; ++c) {
                nextPos[c][i] = nextPos[c][i + 1];  // carry forward
            }
            nextPos[t[i] - 'a'][i] = i;  // overwrite current char
        }
    }

    // For each incoming s: check if it's a subsequence of t
    bool isSubsequence(const string& s) {
        int idx = 0;
        for (char ch : s) {
            idx = nextPos[ch - 'a'][idx];
            if (idx == tLen)
                return false;  // ch not found
            ++idx;             // move to next position in t
        }
        return true;
    }
};

int main() {
    string t = "abcde";
    SubsequenceChecker checker(t);

    vector<string> queries = {"ace", "aec", "abc", "e"};
    for (const string& s : queries) {
        cout << s << ": " << (checker.isSubsequence(s) ? "YES" : "NO") << endl;
    }
    return 0;
}