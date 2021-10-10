#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

class LRUCache
{
public:
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    int capacity;

    LRUCache(int cap)
    {
        capacity = cap;
    }

    int get(int key)
    {
        if (!map.count(key))
        {
            return -1;
        }
        l.splice(l.begin(), l, map[key]);
        return map[key]->second;
    }

    void put(int key, int value)
    {
        if (map.count(key))
        {
            l.splice(l.begin(), l, map[key]);
            l.begin()->second = value;
            // map[key]->second = value;
            return;
        }
        if (l.size() == capacity)
        {
            int k = l.back().first;
            l.pop_back();
            map.erase(k);
        }
        l.push_front({key, value});
        map[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
    SPEED;
    LRUCache *obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl;
    // cout << obj->tail->value;
    return 0;
}