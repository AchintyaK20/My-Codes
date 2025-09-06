## C++ STL Quick Revision Guide

This document summarizes the most commonly used STL containers, functions, and patterns, especially useful for DSA (Data Structures & Algorithms).

---

### 📌 Table of Contents
- [Containers](#containers)
  - [Vector](#vector)
  - [Deque](#deque)
  - [List](#list)
  - [Set / Multiset](#set--multiset)
  - [Map / Multimap](#map--multimap)
  - [Unordered Set / Map](#unordered-set--map)
  - [Stack](#stack)
  - [Queue](#queue)
  - [Priority Queue (Heap)](#priority-queue-heap)
  - [Bitset](#bitset)
- [Utilities](#utilities)
  - [Sorting](#sorting)
  - [Lower Bound / Upper Bound](#lower-bound--upper-bound)
  - [Structs](#structs)
  - [Tuples](#tuples)

---

## Containers

### ✅ Vector
```cpp
vector<int> v;
v.push_back(10);
v.pop_back();
v.erase(v.begin());
v.clear();
bool empty = v.empty();
int sz = v.size();
int x = v.back();
sort(v.begin(), v.end());
reverse(v.begin(), v.end());
```

### ✅ Deque
```cpp
deque<int> dq;
dq.push_front(1);
dq.push_back(2);
dq.pop_front();
dq.pop_back();
dq.erase(dq.begin());
dq.clear();
bool empty = dq.empty();
int sz = dq.size();
```

### ✅ List
```cpp
list<int> l;
l.push_front(1);
l.push_back(2);
l.pop_front();
l.pop_back();
l.erase(l.begin());
l.clear();
bool empty = l.empty();
int sz = l.size();
```

### ✅ Set / Multiset
```cpp
set<int> s;
s.insert(5);
s.erase(5);
s.clear();
bool empty = s.empty();
int sz = s.size();
auto it = s.find(5);  // returns s.end() if not found

multiset<int> ms;
ms.insert(2);
ms.erase(ms.find(2));  // only one occurrence
ms.clear();
bool empty = ms.empty();
```

### ✅ Map / Multimap
```cpp
map<int, int> m;
m[1] = 10;
m.erase(1);
m.clear();
bool empty = m.empty();
int sz = m.size();
m.count(1);  // returns 1 if key exists

multimap<int, int> mm;
mm.insert({1, 100});
mm.erase(1);
mm.clear();
```

### ✅ Unordered Set / Map
```cpp
unordered_set<int> us;
us.insert(1);
us.erase(1);
us.clear();
bool empty = us.empty();

unordered_map<int, int> um;
um[1] = 5;
um.erase(1);
um.clear();
```

### ✅ Stack
```cpp
stack<int> st;
st.push(10);
st.pop();
int x = st.top();
bool empty = st.empty();
int sz = st.size();
```

### ✅ Queue
```cpp
queue<int> q;
q.push(1);
q.pop();
int x = q.front();
bool empty = q.empty();
int sz = q.size();
```

### ✅ Priority Queue (Heap)
#### Max-heap (default):
```cpp
priority_queue<int> pq;
pq.push(3);
pq.pop();
int top = pq.top();
bool empty = pq.empty();
int sz = pq.size();
```

#### Min-heap:
```cpp
priority_queue<int, vector<int>, greater<int>> pq;
pq.push(3);
pq.pop();
```

#### Custom comparator (Lambda + decltype)
```cpp
struct Node {
    int id, cost;
};

// Min-heap by cost
auto cmpMin = [](const Node& a, const Node& b) {
    return a.cost > b.cost;
};
priority_queue<Node, vector<Node>, decltype(cmpMin)> minHeap(cmpMin);

// Max-heap by cost
auto cmpMax = [](const Node& a, const Node& b) {
    return a.cost < b.cost;
};
priority_queue<Node, vector<Node>, decltype(cmpMax)> maxHeap(cmpMax);
```

### ✅ Bitset
```cpp
bitset<8> b("10101010");
b.set(0);
b.reset(1);
b.flip(2);
b.count();       // number of 1s
b.any();         // any 1?
b.none();        // all 0?
b.to_ulong();    // convert to unsigned long
```

---

## Utilities

### ✅ Sorting
```cpp
vector<pair<int, int>> v;
sort(v.begin(), v.end());

// Custom comparator
sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
});
```

### ✅ Lower Bound / Upper Bound
```cpp
vector<int> v = {1, 3, 3, 5, 7};
auto lb = lower_bound(v.begin(), v.end(), 3);  // first >= 3
auto ub = upper_bound(v.begin(), v.end(), 3);  // first > 3
```

### ✅ Structs
```cpp
struct Node {
    int id, cost;

    // Optional: Overload < for STL ordering (e.g., max-heap)
    bool operator<(const Node& other) const {
        return cost < other.cost;  // max-heap behavior
    }
};
```

### ✅ Tuples
```cpp
tuple<int, int, string> t = make_tuple(1, 2, "abc");
int x = get<0>(t);
int y = get<1>(t);
string s = get<2>(t);

auto [a, b, str] = t;  // structured binding (C++17+)
```
