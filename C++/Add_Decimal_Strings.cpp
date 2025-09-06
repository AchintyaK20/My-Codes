#include <iostream>
#include <set>
#include <sstream>
#include <unordered_set>
using namespace std;

string addStrings(string num1, string num2, int &carry) {
    int m = num1.size() - 1, n = num2.size() - 1;
    string res = "";
    while (m >= 0 || n >= 0) {
        int x1 = (m >= 0) ? num1[m] - '0' : 0;
        int x2 = (n >= 0) ? num2[n] - '0' : 0;
        int sum = x1 + x2 + carry;
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
        m--, n--;
    }
    return res;
}

string addDecimalStrings(string &num1, string &num2) {
    vector<string> nums1;
    vector<string> nums2;
    string token;
    stringstream ss1(num1);
    while (getline(ss1, token, '.')) {
        nums1.push_back(token);
    }
    stringstream ss2(num2);
    while (getline(ss2, token, '.')) {
        nums2.push_back(token);
    }

    string decimal1 = nums1.size() > 1 ? nums1[1] : "";
    string decimal2 = nums2.size() > 1 ? nums2[1] : "";

    bool has_decimal = !decimal1.empty() || !decimal2.empty();

    while (decimal1.size() != decimal2.size()) {
        if (decimal1.size() < decimal2.size()) {
            decimal1.push_back('0');
        } else {
            decimal2.push_back('0');
        }
    }

    int carry = 0;
    string result;
    result += addStrings(decimal1, decimal2, carry);

    if (has_decimal) {
        result.push_back('.');
    }

    result += addStrings(nums1[0], nums2[0], carry);
    if (carry) {
        result.push_back(carry + '0');
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string num1;
    string num2;
    cin >> num1 >> num2;
    cout << addDecimalStrings(num1, num2);

    return 0;
}
