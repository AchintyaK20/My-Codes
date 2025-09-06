// C++ STL Revision Template for Data Structures and Algorithms
// Assumes: using namespace std;

#include <math.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// -------- VECTORS --------
void vector_demo() {
    vector<int> v = {1, 2, 3};
    v.push_back(4);
    v.pop_back();
    int n = v.size();
    bool is_empty = v.empty();
    v.clear();

    // Traversal
    for (int x : v)
        cout << x << " ";

    // Sort
    sort(v.begin(), v.end());
    sort(v.rbegin(), v.rend());                // descending
    sort(v.begin(), v.end(), greater<int>());  // this is descending as well

    // Custom sort
    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;  // descending
    });
}

// -------- ARRAYS --------
void array_demo() {
    int arr[] = {5, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);

    // Custom comparator
    sort(arr, arr + n, [](int a, int b) {
        return a > b;
    });
}

// -------- STACK --------
void stack_demo() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.pop();
    int top = s.top();
    bool empty = s.empty();
}

// -------- QUEUE --------
void queue_demo() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.pop();
    int f = q.front();
    int b = q.back();
    bool empty = q.empty();
}

void priority_queue_demo() {
    priority_queue<int> pq;  // max-heap
    pq.push(3);
    pq.push(1);
    pq.push(5);
    int top = pq.top();

    pq.pop();  // 5 will be removed

    // Min-heap
    priority_queue<int, vector<int>, greater<int>> min_pq;

    using pii = pair<int, int>;

    // Max-heap with pair<int, int>
    priority_queue<pii> max_heap_pair;  // by default compares by first, then second

    // Min-heap with pair<int, int>
    priority_queue<pii, vector<pii>, greater<pii>> min_heap_pair;
    min_heap_pair.push({3, 4});

    // Custom max-heap by second
    auto cmp_max = [](pii &a, pii &b) {
        return a.second < b.second;
    };
    priority_queue<pii, vector<pii>, decltype(cmp_max)> max_heap_by_second(cmp_max);

    // Custom min-heap by second
    auto cmp_min = [](pii &a, pii &b) {
        return a.second > b.second;
    };
    priority_queue<pii, vector<pii>, decltype(cmp_min)> min_heap_by_second(cmp_min);

    // With struct and comparator
    struct Node {
        int val, cost;
    };

    auto max_heap_by_cost = [](Node &a, Node &b) {
        return a.cost < b.cost;
    };
    priority_queue<Node, vector<Node>, decltype(max_heap_by_cost)> max_heap_struct(max_heap_by_cost);

    // Insertion
    Node obj = {3, 5};
    max_heap_struct.push(obj);

    auto min_heap_by_cost = [](Node &a, Node &b) {
        return a.cost > b.cost;
    };
    priority_queue<Node, vector<Node>, decltype(min_heap_by_cost)> min_heap_struct(min_heap_by_cost);

    // With tuple
    using tiii = tuple<int, int, int>;  // (dist, u, v)

    auto cmp_tuple = [](tiii a, tiii b) {
        return get<0>(a) > get<0>(b);  // Min-heap by first element
    };
    priority_queue<tiii, vector<tiii>, decltype(cmp_tuple)> pq_tuple(cmp_tuple);
}

// -------- DEQUE --------
void deque_demo() {
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    dq.pop_back();
    dq.pop_front();
    int f = dq.front();
    int b = dq.back();
}

// -------- SET --------
void set_demo() {
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.erase(3);
    bool exists = s.count(1);
    auto it = s.find(1);

    // lower_bound / upper_bound
    auto lb = s.lower_bound(2);  // >= 2
    auto ub = s.upper_bound(2);  // > 2
    cout << *lb << " " << *ub << endl;

    // Custom comparator (descending)
    set<int, greater<int>> desc_set;
}

// -------- MULTISET --------
void multiset_demo() {
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.erase(ms.find(1));

    // lower_bound / upper_bound
    auto lb = ms.lower_bound(1);
    auto ub = ms.upper_bound(1);
}

// -------- MAP --------
void map_demo() {
    map<string, int> mp;
    mp["apple"] = 2;
    mp["banana"] = 3;
    int x = mp["apple"];
    mp.erase("banana");
    bool exists = mp.count("apple");

    // lower_bound / upper_bound
    auto lb = mp.lower_bound("apple");
    auto ub = mp.upper_bound("apple");

    // Custom comparator
    map<int, int, greater<int>> desc_map;

    // Custom comparator
    auto cmp = [](int a, int b) {
        return a > b;
    };
    map<int, string, decltype(cmp)> m(cmp);

    // Map with custom struct
    struct Person {
        string name;
        int age;
    };
    auto sortedByAge = [](Person a, Person b) {
        return a.age < b.age;
    };
    map<Person, string, decltype(sortedByAge)> personMap(sortedByAge);

    personMap[{"Alice", 30}] = "Engineer";
    personMap[{"Bob", 25}] = "Designer";
    personMap[{"Charlie", 35}] = "Manager";
    for (auto &x : personMap) {
        cout << x.first.name << " " << x.first.age << " " << x.second << endl;
    }
}

// -------- UNORDERED SET / MAP --------
void unordered_demo() {
    unordered_set<int> us;
    unordered_map<string, int> um;
}

// -------- PAIR --------
void pair_demo() {
    pair<int, int> p = {1, 2};
    int x = p.first;
    int y = p.second;

    // With tie
    vector<pair<int, int>> vp;
    sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;  // sort by second element
    });
}

// -------- ALGORITHMS --------
void algorithm_demo() {
    vector<int> v = {1, 2, 3};
    reverse(v.begin(), v.end());
    int mx = *max_element(v.begin(), v.end());
    int mn = *min_element(v.begin(), v.end());
    int sum = accumulate(v.begin(), v.end(), 0);
    int idx = find(v.begin(), v.end(), 2) - v.begin();
    int ct = count(v.begin(), v.end(), 2);
    next_permutation(v.begin(), v.end());
    prev_permutation(v.begin(), v.end());

    // lower_bound / upper_bound on vector
    sort(v.begin(), v.end());
    auto lb = lower_bound(v.begin(), v.end(), 2);  // >= 2
    auto ub = upper_bound(v.begin(), v.end(), 2);  // > 2
}

// -------- BITSET --------
void bitset_demo() {
    bitset<8> b1;                      // All bits 0: 00000000
    bitset<8> b2(42);                  // Binary of 42: 00101010
    bitset<8> b3(string("10110011"));  // From string

    cout << "b1 = " << b1 << endl;
    cout << "b2 = " << b2 << endl;
    cout << "b3 = " << b3 << endl;

    // Set and reset
    b1.set(1);    // Set bit at index 1 to 1 → 00000010
    b1.set();     // Set all bits to 1 → 11111111
    b1.reset(2);  // Reset bit at index 2 → 11111011
    b1.reset();   // Reset all bits → 00000000

    // Bitwise operations
    cout << "b2 & b3 = " << (b2 & b3) << endl;
    cout << "b2 | b3 = " << (b2 | b3) << endl;
    cout << "~b2     = " << (~b2) << endl;

    // Access and check
    cout << "b2[1] = " << b2[1] << endl;            // Get bit at index 1
    cout << "b2.count() = " << b2.count() << endl;  // # of 1s
    cout << "b2.any() = " << b2.any() << endl;      // true if any 1
    cout << "b2.none() = " << b2.none() << endl;    // true if all 0
    cout << "b2.test(3) = " << b2.test(3) << endl;  // check if bit 3 is 1
}

int main() {
    vector_demo();
    array_demo();
    stack_demo();
    queue_demo();
    priority_queue_demo();
    deque_demo();
    set_demo();
    multiset_demo();
    map_demo();
    unordered_demo();
    pair_demo();
    algorithm_demo();
    bitset_demo();
    return 0;
}
