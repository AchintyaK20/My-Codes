#include <iostream>
#include <set>
#include <sstream>
#include <unordered_set>
using namespace std;

class NestedInteger {
private:
    variant<int, vector<NestedInteger>> value;

public:
    // Constructor initializes an empty nested list.
    NestedInteger() : value(vector<NestedInteger>()) {}

    // Constructor initializes a single integer.
    NestedInteger(int val) : value(val) {}

    // Return true if this NestedInteger holds a single integer.
    bool isInteger() const {
        return holds_alternative<int>(value);
    }

    // Return the single integer that this NestedInteger holds.
    // Throws if it doesn't hold an integer.
    int getInteger() const {
        if (!isInteger())
            throw runtime_error("Not an integer");
        return get<int>(value);
    }

    // Set this NestedInteger to hold a single integer.
    void setInteger(int val) {
        value = val;
    }

    // Set this NestedInteger to hold a nested list and add a NestedInteger to it.
    void add(const NestedInteger &ni) {
        if (!holds_alternative<vector<NestedInteger>>(value)) {
            value = vector<NestedInteger>();
        }
        get<vector<NestedInteger>>(value).push_back(ni);
    }

    // Return the nested list.
    const vector<NestedInteger> &getList() const {
        if (isInteger())
            throw runtime_error("Not a list");
        return get<vector<NestedInteger>>(value);
    }

    // Optional: return a modifiable list (for advanced usage)
    vector<NestedInteger> &getList() {
        if (isInteger())
            throw runtime_error("Not a list");
        return get<vector<NestedInteger>>(value);
    }
};

void printItems(vector<NestedInteger> &list) {
    for (auto &ni : list) {
        if (ni.isInteger()) {
            cout << ni.getInteger() << " ";
        } else {
            printItems(ni.getList());
        }
    }
}

int main() {
    NestedInteger x;
    x.add(NestedInteger(1));
    NestedInteger y;
    y.add(NestedInteger(4));
    NestedInteger z;
    z.add(NestedInteger(6));
    z.add(NestedInteger(7));
    z.add(NestedInteger(10));
    y.add(z);
    x.add(y);

    printItems(x.getList());
    cout << endl;

    NestedInteger a(5);
    cout << a.isInteger() << " -> " << a.getInteger() << endl;

    NestedInteger b;
    b.add(NestedInteger(10));
    b.add(a);

    cout << "b isInteger? " << b.isInteger() << endl;

    for (const auto &ni : b.getList()) {
        if (ni.isInteger())
            cout << ni.getInteger() << " ";
    }
    cout << endl;

    return 0;
}
