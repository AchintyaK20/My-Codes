# C++ STL Revision Cheat Sheet

Quick, example-driven reference for common C++ Standard Library components used in competitive programming, interviews, and systems coding. Each section has minimal snippets you can paste and adapt. Target standard: **C++17** (notes for C++20+ where helpful).

---

## 1. Fast I/O Setup

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

---

## 2. Containers Overview

| Category                       | Containers                                                                   |
| ------------------------------ | ---------------------------------------------------------------------------- |
| Sequence                       | `vector`, `array`, `deque`, `list`, `forward_list`, `string`                 |
| Adapters                       | `stack`, `queue`, `priority_queue`                                           |
| Associative (ordered, RB tree) | `set`, `multiset`, `map`, `multimap`                                         |
| Unordered (hash)               | `unordered_set`, `unordered_multiset`, `unordered_map`, `unordered_multimap` |
| Other                          | `bitset`, `span` (C++20), `valarray`, `pair`, `tuple`                        |

---

## 3. `vector`

```cpp
vector<int> v = {1, 2, 3};
v.push_back(4);
v.pop_back();
size_t n = v.size();
bool empty = v.empty();
v.clear();

for (int x : v) {
    // ...
}

// Sorting
sort(v.begin(), v.end());
sort(v.rbegin(), v.rend());
sort(v.begin(), v.end(), greater<int>());
sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

// Remove element idiom
v.erase(remove(v.begin(), v.end(), 5), v.end());

// Lower/upper bound (requires sorted)
auto it = lower_bound(v.begin(), v.end(), 10);
```

---

## 4. `array` (C-style / `std::array`)

```cpp
// C-style array
int a[] = {5, 2, 3, 1};
int n = sizeof(a) / sizeof(a[0]);
sort(a, a + n, greater<int>());

// std::array
array<int, 4> b{5, 2, 3, 1};
sort(b.begin(), b.end());
```

---

## 5. `deque`

```cpp
deque<int> dq;
dq.push_back(1);
dq.push_front(2);
dq.pop_back();
dq.pop_front();
int f = dq.front();
int b = dq.back();
```

---

## 6. `list` (bidirectional)

```cpp
list<int> lst = {1, 2, 3};

// insert before 2nd element
auto it = lst.insert(next(lst.begin()), 10);
// erase that element
lst.erase(it);

lst.remove(2);      // removes all values equal to 2
lst.unique();       // removes consecutive duplicates
lst.sort();         // O(n log n)
```

---

## 7. `forward_list` (singly linked)

```cpp
forward_list<int> fl = {3, 1, 2};
fl.push_front(5);
fl.remove(1);   // remove all occurrences of 1
fl.sort();
```

---

## 8. `stack` / `queue` / `priority_queue`

```cpp
// stack
stack<int> st;
st.push(1);
int topVal = st.top();
st.pop();

// queue
queue<int> q;
q.push(1);
int frontVal = q.front();
q.pop();

// max-heap (default)
priority_queue<int> pq;
pq.push(5);
int maxVal = pq.top();
pq.pop();

// min-heap
priority_queue<int, vector<int>, greater<int>> minpq;
minpq.push(7);

// custom comparator (by second of pair)
using pii = pair<int, int>;
auto cmp = [](const pii &a, const pii &b) { return a.second > b.second; };
priority_queue<pii, vector<pii>, decltype(cmp)> pq2(cmp);
```

---

## 9. `set` / `multiset`

```cpp
set<int> s = {3, 1, 4};
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
// erase a single occurrence (iterator required)
ms.erase(ms.find(1));
```

---

## 10. `map` / `multimap`

```cpp
map<string,int> mp;
mp["apple"] = 2;
mp["banana"] = 5;
int x = mp["apple"];              // inserts default 0 if missing
bool ex = mp.count("apple");     // 0 or 1
mp.erase("banana");

for (auto &[k, v] : mp) {
    // iterate in key-sorted order
}

auto lb = mp.lower_bound("app");  // first key >= "app"

// custom comparator (descending key)
map<int, int, greater<int>> dmp;

// Struct key with custom comparator
struct Person { string name; int age; };
struct Cmp {
    bool operator()(const Person &a, const Person &b) const {
        return a.age < b.age; // sort by age ascending
    }
};
map<Person, string, Cmp> people;
```

---

## 11. `unordered_map` / `unordered_set`

```cpp
unordered_map<string,int> um;
um.reserve(1 << 15); // reduce rehash operations
um["key"] = 10;
um.erase("key");

for (auto &[k, v] : um) {
    // iteration order is unspecified
}

unordered_set<int> us;
us.insert(5);
bool h = us.count(5);

// Custom hash for pair<int,int>
struct PairHash {
    size_t operator()(const pair<int,int> &p) const noexcept {
        return (static_cast<uint64_t>(p.first) << 32) ^ static_cast<uint64_t>(p.second);
    }
};

unordered_map<pair<int,int>, int, PairHash> grid;
```

---

## 12. `pair` / `tuple` / `tie` / structured binding

```cpp
pair<int,int> p = {1, 2};
int a, b;
tie(a, b) = p;          // tie unpack

auto [x1, x2] = p;      // structured binding (C++17)

// tuple
tuple<int, string, double> t(1, "hi", 3.5);
auto [i, s, d] = t;
```

---

## 13. Algorithms (`<algorithm>`, `<numeric>`)

```cpp
vector<int> v = {1, 2, 3, 4, 5};

shuffle(v.begin(), v.end(), rng);   // rng: mt19937
reverse(v.begin(), v.end());
int mx = *max_element(v.begin(), v.end());
int mn = *min_element(v.begin(), v.end());
int sum = accumulate(v.begin(), v.end(), 0);

int idx = find(v.begin(), v.end(), 3) - v.begin();
int ct  = count(v.begin(), v.end(), 2);
next_permutation(v.begin(), v.end());
prev_permutation(v.begin(), v.end());

bool allpos = all_of(v.begin(), v.end(), [](int x){ return x > 0; });
bool anyneg = any_of(v.begin(), v.end(), [](int x){ return x < 0; });

// partial sums
vector<int> pref;
partial_sum(v.begin(), v.end(), back_inserter(pref));

// binary-search related (requires sorted)
sort(v.begin(), v.end());
auto lb = lower_bound(v.begin(), v.end(), 4);
auto ub = upper_bound(v.begin(), v.end(), 4);
bool ok = binary_search(v.begin(), v.end(), 4);
```

---

## 14. `bitset`

```cpp
bitset<8> b1;
bitset<8> b2(42);
bitset<8> b3(string("10110011"));

b1.set();        // all bits 1
b1.reset(2);     // clear bit 2
b1.flip(3);      // toggle bit 3

int ones = b1.count();
bool any = b1.any();

auto mask = (b2 & b3) | (~b2);
```

---

## 15. Numeric Helpers

```cpp
int g = gcd(48, 18);
int l = lcm(12, 18);

long long pw = 1;
const long long MOD = 1e9 + 7;
long long a = 2, b = 50;  // compute a^b % MOD
while (b) {
    if (b & 1) pw = pw * a % MOD;
    a = a * a % MOD;
    b >>= 1;
}

// iota fill 0..9
vector<int> ord(10);
iota(ord.begin(), ord.end(), 0);
```

---

## 16. Utility: iterator / `back_inserter` / `emplace`

```cpp
vector<pair<int,int>> vp;
vp.emplace_back(1, 2);

vector<int> to;
copy(v.begin(), v.end(), back_inserter(to));
```

---

## 17. String utilities

```cpp
string s = "abc";
s.push_back('d');
s.pop_back();
string sub = s.substr(1, 2); // from index 1, length 2
size_t pos = s.find("bc"); // npos if not found
reverse(s.begin(), s.end());

int x = stoi("123");
long long y = stoll("9999999999");
string t = to_string(12345);
```

---

## 18. `string_view` (C++17)

```cpp
string_view sv = "abcdef";
auto sub = sv.substr(2, 3);
// Non-owning view: ensure original data outlives the view
```

---

## 19. `optional`, `variant`, `any`

```cpp
optional<int> oi;
oi = 5;
if (oi) cout << *oi;

variant<int, string, double> var;
var = 10;
var = string("hi");
visit([](auto &&val) { cout << val; }, var);

any a2 = 42;
if (a2.has_value()) cout << any_cast<int>(a2);
```

---

## 20. `chrono` timing

```cpp
using namespace chrono;
auto st = high_resolution_clock::now();
// ... work ...
auto ed = high_resolution_clock::now();
cout << duration_cast<microseconds>(ed - st).count() << " us\n";
```

---

## 21. Random

```cpp
mt19937 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist(1, 100);
int r = dist(rng);
shuffle(v.begin(), v.end(), rng);
```

---

## 22. Filesystem (C++17)

```cpp
#include <filesystem>
namespace fs = std::filesystem;
for (auto &p : fs::directory_iterator(".")) {
    cout << p.path() << "\n";
}
```

---

## 23. Smart Pointers

```cpp
unique_ptr<int> up = make_unique<int>(5);
shared_ptr<int> sp = make_shared<int>(10);
weak_ptr<int> wp = sp; // observe without ownership

if (auto locked = wp.lock()) {
    // use *locked safely
}
```

---

## 24. Custom Hash / Equality (robust for CP)

```cpp
struct SafeHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const noexcept {
        static const uint64_t FIXED = (uint64_t)chrono::steady_clock::now().time_since_epoch().count();
        return static_cast<size_t>(splitmix64(x + FIXED));
    }
};

unordered_map<long long, int, SafeHash> safe;
```

---

## 25. Memory / Alignment Helpers

```cpp
alignas(64) int buf[256]; // reduce false sharing
```

---

## 26. Debug Helpers

```cpp
#define DBG(x) cerr << #x << " = " << (x) << "\n";
```

---

## 27. Common Patterns

```cpp
// 1. Erase-remove
v.erase(remove(v.begin(), v.end(), value), v.end());

// 2. Min heap for Dijkstra
using T = tuple<int, int, int>; // dist, node, parent
priority_queue<T, vector<T>, greater<T>> pq;

// 3. Coordinate compression
vector<int> a;          // original
vector<int> b = a;
sort(b.begin(), b.end());
b.erase(unique(b.begin(), b.end()), b.end());
int id = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
```

---

## 28. Multithreading (C++11 basic)

```cpp
#include <thread>

void work(int id) { /* ... */ }

int main() {
    thread t1(work, 1);
    thread t2(work, 2);
    t1.join();
    t2.join();
}
```

---

## 29. Exceptions (brief)

```cpp
try {
    throw runtime_error("fail");
} catch (const exception &e) {
    cerr << e.what();
}
```

---

## 30. Compile Flags (example)

```bash
clang++ -std=c++17 -O2 -Wall -Wextra -Wshadow -DLOCAL code.cpp -o run
```

---

### Quick Reference Tables

**Complexity (typical)**

- `vector`: push\_back amortized O(1), insert/erase middle O(n)
- `deque`: push/pop both ends O(1)
- `list`: insert/erase O(1) with iterator, traversal O(n)
- `set`/`map`: O(log n)
- `unordered_set`/`unordered_map`: average O(1), worst O(n)
- `priority_queue` push/pop O(log n)

**Iterator Categories**

- Input/Output: `istream_iterator`, `ostream_iterator`
- Forward: `forward_list`
- Bidirectional: `list`, `set`, `map`, `multiset`, `multimap`
- Random Access: `vector`, `deque`, `array`, `string`

---

### Minimal Template

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
```
