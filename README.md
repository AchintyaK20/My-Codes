# C++ STL Revision Cheat Sheet

Quick, example-driven reference for common C++ Standard Library components used in competitive programming, interviews, and systems coding. Each section has minimal snippets you can paste and adapt. Target standard: C++17 (notes for C++20+ where helpful).

---
## 1. Fast I/O Setup
```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

---
## 2. Containers Overview
| Category | Containers |
|----------|-----------|
| Sequence | vector, array, deque, list, forward_list, string |
| Adapters | stack, queue, priority_queue |
| Associative (ordered, RB tree) | set, multiset, map, multimap |
| Unordered (hash) | unordered_set, unordered_multiset, unordered_map, unordered_multimap |
| Other | bitset, span(C++20), valarray, pair, tuple |

---
## 3. vector
```cpp
vector<int> v = {1,2,3};
v.push_back(4); v.pop_back();
int n = v.size(); bool empty = v.empty();
v.clear();
for (int x : v) {/*...*/}
// Sorting
sort(v.begin(), v.end());
sort(v.rbegin(), v.rend());
sort(v.begin(), v.end(), greater<int>());
sort(v.begin(), v.end(), [](int a,int b){return a>b;});
// Remove element idiom
v.erase(remove(v.begin(), v.end(), 5), v.end());
// Lower/upper bound (needs sorted)
auto it = lower_bound(v.begin(), v.end(), 10);
```

## 4. array (raw / std::array)
```cpp
int a[] = {5,2,3,1}; int n = sizeof(a)/sizeof(a[0]);
sort(a, a+n, greater<int>());
array<int,4> b{5,2,3,1}; sort(b.begin(), b.end());
```

## 5. deque
```cpp
deque<int> dq; dq.push_back(1); dq.push_front(2);
dq.pop_back(); dq.pop_front();
int f = dq.front(); int b = dq.back();
```

## 6. list (bidirectional)
```cpp
list<int> lst = {1,2,3};
auto it = lst.insert(next(lst.begin()), 10);
lst.erase(it);
lst.remove(2);      // removes all 2s
lst.unique();       // consecutive duplicates
lst.sort();
```



## 7. forward_list (singly linked)

```cpp
bool empty = v.empty();

// Clear all elements
v.clear();

// Range-based loop
for (int x : v) {
    // use x
}

// Sorting (ascending / descending)
sort(v.begin(), v.end());
sort(v.rbegin(), v.rend());
sort(v.begin(), v.end(), greater<int>());           // also descending
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;                                    // custom comparator
});

// Erase-remove idiom (remove every 5)
v.erase(remove(v.begin(), v.end(), 5), v.end());

// Lower bound (needs sorted vector)
forward_list<int> fl = {3,1,2};
fl.push_front(5);
fl.remove(1);
fl.sort();
```
int n = sizeof(a) / sizeof(a[0]);
sort(a, a + n, greater<int>());

array<int, 4> b {5, 2, 3, 1};
sort(b.begin(), b.end());

## 8. stack / queue / priority_queue
```cpp
stack<int> st; st.push(1); st.top(); st.pop();

dq.push_back(1);
dq.push_front(2);

dq.pop_back();
dq.pop_front();

int f = dq.front();
int b = dq.back();
queue<int> q; q.push(1); q.front(); q.pop();
// Max-heap (default)
priority_queue<int> pq; pq.push(5); pq.top(); pq.pop();
// Min-heap

auto it = lst.insert(next(lst.begin()), 10); // insert before 2nd element
lst.erase(it);                               // erase that element

lst.remove(2);    // remove all occurrences of 2
lst.unique();     // remove consecutive duplicates
lst.sort();       // O(n log n)
priority_queue<int, vector<int>, greater<int>> minpq;
// Custom (by second of pair)
using pii = pair<int,int>;
auto cmp = [](const pii &a,const pii &b){return a.second > b.second;};

fl.push_front(5);
fl.remove(1);  // remove all occurrences of 1
fl.sort();
priority_queue<pii, vector<pii>, decltype(cmp)> pq2(cmp);
```

## 9. set / multiset

st.push(1);
int topVal = st.top();
st.pop();

queue<int> q;
q.push(1);
int frontVal = q.front();
q.pop();

// Max-heap (default)
priority_queue<int> pq;
pq.push(5);
int maxVal = pq.top();
pq.pop();

// Min-heap
priority_queue<int, vector<int>, greater<int>> minpq;
minpq.push(7);

// Custom comparator (order by second ascending)
using pii = pair<int, int>;
auto cmp = [](const pii &a, const pii &b) {
    return a.second > b.second;  // creates min-heap by second
};
priority_queue<pii, vector<pii>, decltype(cmp)> pq2(cmp);
```cpp
set<int> s = {3,1,4}; s.insert(2); s.erase(3);
bool has = s.count(1);
auto it = s.find(4);
s.insert(2);
s.erase(3);

bool has = s.count(1);
auto it = s.find(4);

auto lb = s.lower_bound(2);  // first >= 2
auto ub = s.upper_bound(2);  // first > 2

set<int, greater<int>> ds;   // descending order

multiset<int> ms;
ms.insert(1);
ms.insert(1);
ms.erase(ms.find(1)); // erase single occurrence (first iterator)
auto lb = s.lower_bound(2); // >= 2
auto ub = s.upper_bound(2); // > 2
set<int, greater<int>> ds;  // descending
multiset<int> ms; ms.insert(1); ms.insert(1);
mp["apple"]  = 2;   // insert / assign
mp["banana"] = 5;

int x  = mp["apple"];         // O(log n)
bool ex = mp.count("apple");   // 0 or 1

mp.erase("banana");

for (auto &[k, v] : mp) {
    // iterate in key-sorted order
}

auto lb = mp.lower_bound("app");  // first key >= "app"

// Custom comparator (descending key)
map<int, int, greater<int>> dmp;

// Struct key with custom comparator
struct Person { string name; int age; };
struct Cmp {
    bool operator()(Person const &a, Person const &b) const {
        return a.age < b.age;   // sort by age ascending
    }
};
map<Person, string, Cmp> people;
ms.erase(ms.find(1)); // erase single occurrence
```

## 10. map / multimap
um.reserve(1 << 15);  // reduce rehash operations
um["key"] = 10;
um.erase("key");

for (auto &[k, v] : um) {
    // iter order is unspecified
}

unordered_set<int> us;
us.insert(5);
bool h = us.count(5);

// Custom hash for pair<int,int>
struct Hash {
    size_t operator()(const pair<int, int> &p) const noexcept {
        return (static_cast<uint64_t>(p.first) << 32) ^ p.second;
    }
};

```cpp
map<string,int> mp; mp["apple"] = 2; mp["banana"] = 5;
int x = mp["apple"]; bool ex = mp.count("apple");
mp.erase("banana");
for (auto &[k,v] : mp) {}

int a, b;
tie(a, b) = p;          // tie unpack

auto [x1, x2] = p;      // structured binding (C++17)

// Sort vector of pairs by second
sort(vp.begin(), vp.end(), [](auto &A, auto &B) {
    return A.second < B.second;
});

// tuple
tuple<int, string, double> t(1, "hi", 3.5);
auto [i, s, d] = t;
auto lb = mp.lower_bound("app");
// Custom comparator
map<int,int, greater<int>> dmp;
// With struct key

reverse(v.begin(), v.end());

int mx  = *max_element(v.begin(), v.end());
int mn  = *min_element(v.begin(), v.end());
int sum = accumulate(v.begin(), v.end(), 0);

int idx = find(v.begin(), v.end(), 3) - v.begin();
int ct  = count(v.begin(), v.end(), 2);

next_permutation(v.begin(), v.end());
prev_permutation(v.begin(), v.end());

// Predicates
bool allpos = all_of(v.begin(), v.end(), [](int x) { return x > 0; });
bool anyneg = any_of(v.begin(), v.end(), [](int x) { return x < 0; });

// Stable partition (evens first)
stable_partition(v.begin(), v.end(), [](int x) { return x % 2 == 0; });

// Prefix sums
vector<int> pref;
partial_sum(v.begin(), v.end(), back_inserter(pref));

// Must be sorted for binary search related
sort(v.begin(), v.end());
auto lb = lower_bound(v.begin(), v.end(), 4);  // first >= 4
auto ub = upper_bound(v.begin(), v.end(), 4);  // first > 4
bool ok = binary_search(v.begin(), v.end(), 4);
struct Person { string name; int age; };
struct Cmp { bool operator()(Person const& a, Person const& b) const {return a.age < b.age;} };
map<Person,string,Cmp> people;
```
bitset<8> b2(42);             // 00101010
bitset<8> b3(string("10110011"));

b1.set();        // all bits 1
b1.reset(2);     // clear bit 2
b1.flip(3);      // toggle bit 3

int ones = b1.count();
bool any  = b1.any();

auto mask = (b2 & b3) | (~b2);

## 11. unordered_map / unordered_set
```cpp
unordered_map<string,int> um; um.reserve(1<<15); // minimize rehash
int l = lcm(12, 18);

long long powMod = 1;
const long long MOD = 1e9 + 7;
long long a = 2, b = 50;  // compute a^b % MOD
while (b) {
    if (b & 1) powMod = powMod * a % MOD;
    a = a * a % MOD;
    b >>= 1;
}

// iota fill 0..9
vector<int> ord(10);
iota(ord.begin(), ord.end(), 0);
um["key"] = 10; um.erase("key");
for (auto &[k,v] : um) {}
unordered_set<int> us; us.insert(5); bool h = us.count(5);
// Custom hash for pair
vp.emplace_back(1, 2);           // construct in place

vector<int> src = {1, 2, 3};
vector<int> to;
copy(src.begin(), src.end(), back_inserter(to));
struct Hash {
    size_t operator()(const pair<int,int>& p) const noexcept {
        return ((uint64_t)p.first<<32) ^ p.second;
    }
s.push_back('d');
s.pop_back();

auto sub = s.substr(1, 2);   // from index 1, length 2
auto pos = s.find("bc");     // npos if not found

reverse(s.begin(), s.end());

// Conversions
int x = stoi("123");
long long y = stoll("9999999999");
string t = to_string(12345);
};
unordered_map<pair<int,int>, int, Hash> grid;
```

auto part = sv.substr(2, 3);   // "cde"
// Non-owning view: ensure original data outlives the view
## 12. pair / tuple / tie / structured binding
```cpp
pair<int,int> p = {1,2}; int a,b; tie(a,b)=p;
auto [x1,x2] = p; // C++17
oi = 5;
if (oi) cout << *oi;

variant<int, string, double> var;
var = 10;
var = string("hi");
visit([](auto &&val) { cout << val; }, var);

any a2 = 42;
if (a2.has_value()) cout << any_cast<int>(a2);
// Sorting vector of pairs by second
sort(vp.begin(), vp.end(), [](auto &A, auto &B){return A.second < B.second;});
// tuple
tuple<int,string,double> t(1,"hi",3.5);

auto start = high_resolution_clock::now();
// ... work ...
auto finish = high_resolution_clock::now();

auto us = duration_cast<microseconds>(finish - start).count();
cout << us << " us\n";
auto [i,s,d] = t;
```

## 13. Algorithms ( <algorithm>, <numeric> )
    (uint64_t) chrono::steady_clock::now().time_since_epoch().count()
);

```cpp
int r = dist(rng);

shuffle(v.begin(), v.end(), rng);
vector<int> v = {1,2,3,4,5};
reverse(v.begin(), v.end());
int mx = *max_element(v.begin(), v.end());
int mn = *min_element(v.begin(), v.end());
int sum = accumulate(v.begin(), v.end(), 0);

for (auto &p : fs::directory_iterator(".")) {
    cout << p.path() << '\n';
}
int idx = find(v.begin(), v.end(), 3) - v.begin();
int ct  = count(v.begin(), v.end(), 2);
next_permutation(v.begin(), v.end());
prev_permutation(v.begin(), v.end());

shared_ptr<int> sp = make_shared<int>(10);
weak_ptr<int> wp = sp;  // observe without owning

if (auto locked = wp.lock()) {
    // use *locked safely
}
// All of condition
bool allpos = all_of(v.begin(), v.end(), [](int x){return x>0;});
// Any / None
bool anyneg = any_of(v.begin(), v.end(), [](int x){return x<0;});
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const noexcept {
        static const uint64_t FIXED = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED);
    }
};

// Partition
stable_partition(v.begin(), v.end(), [](int x){return x%2==0;});
// Partial sums / prefix sums
vector<int> pref; partial_sum(v.begin(), v.end(), back_inserter(pref));
// Lower / upper bound on sorted
sort(v.begin(), v.end());
auto lb = lower_bound(v.begin(), v.end(), 4);
auto ub = upper_bound(v.begin(), v.end(), 4);
// Binary search
bool ok = binary_search(v.begin(), v.end(), 4);
```

## 14. bitset
v.erase(remove(v.begin(), v.end(), value), v.end());

// 2. Min-heap for Dijkstra (distance, node, parent)
using T = tuple<int, int, int>;
priority_queue<T, vector<T>, greater<T>> pq;

// 3. Coordinate compression
vector<int> a;          // original
auto b = a;
sort(b.begin(), b.end());
b.erase(unique(b.begin(), b.end()), b.end());
int id = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
```cpp
bitset<8> b1; bitset<8> b2(42); bitset<8> b3(string("10110011"));
b1.set(); b1.reset(2); b1.flip(3);
int ones = b1.count(); bool any = b1.any();

void work(int id) {
    // do something
}

int main() {
    thread t1(work, 1);
    thread t2(work, 2);
    t1.join();
    t2.join();
}
auto x = (b2 & b3) | (~b2);
```

## 15. Numeric Helpers
    throw runtime_error("fail");
} catch (const exception &e) {
    cerr << e.what();
}
```cpp
int g = gcd(48,18); int l = lcm(12,18);
long long pw = 1; const long long M=1e9+7; long long a=2,b=50; 
while(b){ if(b&1) pw=pw*a%M; a=a*a%M; b>>=1; }
// iota fill
vector<int> ord(10); iota(ord.begin(), ord.end(), 0);
```

## 16. Utility: iterator / back_inserter / emplace
```cpp
vector<pair<int,int>> vp; vp.emplace_back(1,2);
vector<int> to; copy(v.begin(), v.end(), back_inserter(to));
```

## 17. String utilities
```cpp
string s = "abc"; s.push_back('d'); s.pop_back();
s.substr(1,2); // from 1 length 2
s.find("bc"); // npos if not found
reverse(s.begin(), s.end());
// Convert
int x = stoi("123"); long long y = stoll("9999999999");
string t = to_string(12345);
```

## 18. string_view (C++17)
```cpp
string_view sv = "abcdef"; auto sub = sv.substr(2,3);
// No allocation slicing, beware lifetime of original buffer
```

## 19. optional, variant, any
```cpp
optional<int> oi; oi = 5; if(oi) cout << *oi;
variant<int,string,double> var; var = 10; var = string("hi");
visit([](auto &&val){ cout << val; }, var);
any a2 = 42; if(a2.has_value()) cout << any_cast<int>(a2);
```

## 20. chrono timing
```cpp
using namespace chrono;
auto st = high_resolution_clock::now();
// ... work ...
auto ed = high_resolution_clock::now();
cout << duration_cast<microseconds>(ed-st).count() << " us\n";
```

## 21. random
```cpp
mt19937 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist(1,100);
int r = dist(rng);
shuffle(v.begin(), v.end(), rng);
```

## 22. Filesystem (C++17)
```cpp
#include <filesystem>
namespace fs = std::filesystem;
for (auto &p : fs::directory_iterator(".")) {
    cout << p.path() << "\n";
}
```

## 23. Smart Pointers
```cpp
unique_ptr<int> up = make_unique<int>(5);
shared_ptr<int> sp = make_shared<int>(10);
weak_ptr<int> wp = sp; // observe without ownership
if(auto locked = wp.lock()) { /* use *locked */ }
```

## 24. Custom Hash / Equality (robust for CP)
```cpp
struct SafeHash {
    static uint64_t splitmix64(uint64_t x){
        x += 0x9e3779b97f4a7c15; x = (x ^ (x>>30))*0xbf58476d1ce4e5b9; x = (x ^ (x>>27))*0x94d049bb133111eb; return x ^ (x>>31);
    }
    size_t operator()(uint64_t x) const noexcept {
        static const uint64_t FIXED = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED);
    }
};
unordered_map<long long,int, SafeHash> safe;
```

## 25. Memory / Alignment Helpers
```cpp
alignas(64) int buf[256]; // reduce false sharing
```

## 26. Debug Helpers
```cpp
#define DBG(x) cerr << #x << " = " << (x) << "\n";
```

## 27. Common Patterns
```cpp
// 1. Erase-remove
v.erase(remove(v.begin(), v.end(), value), v.end());
// 2. Min heap Dijkstra
using T = tuple<int,int,int>; // dist,node,parent
priority_queue<T, vector<T>, greater<T>> pq;
// 3. Coordinate compression
vector<int> a; auto b=a; sort(b.begin(), b.end()); b.erase(unique(b.begin(), b.end()), b.end());
int id = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
```

## 28. Multithreading (C++11 basic)
```cpp
#include <thread>
void work(int id){ /* ... */ }
int main(){
  thread t1(work,1), t2(work,2);
  t1.join(); t2.join();
}
```

## 29. Exceptions (brief)
```cpp
try { throw runtime_error("fail"); }
catch(const exception &e){ cerr << e.what(); }
```

## 30. Compile Flags (example)
```bash
clang++ -std=c++17 -O2 -Wall -Wextra -Wshadow -DLOCAL code.cpp -o run
```

---
### Quick Reference Tables

Complexity (typical):
- vector: push_back amortized O(1), insert/erase middle O(n)
- deque: push/pop both ends O(1)
- list: insert/erase O(1) with iterator, traversal O(n)
- set/map: O(log n)
- unordered_set/unordered_map: average O(1), worst O(n)
- priority_queue push/pop O(log n)

Iterator Categories:
- Input/Output: istream_iterator, ostream_iterator
- Forward: forward_list
- Bidirectional: list, set, map, multiset, multimap
- Random Access: vector, deque, array, string

---
### Minimal Template
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // code
}
```

---
## Missing Something?
Open an issue or extend `C++/C++_STL_Revision.cpp` and regenerate.

Happy hacking! 🔧
