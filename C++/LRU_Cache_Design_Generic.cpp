#include <iostream>
#include <unordered_map>
using namespace std;

template <typename K, typename V>
class LRUCache {
private:
    struct Node {
        K key;
        V val;
        Node* next;
        Node* prev;
        Node(K k, V v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    unordered_map<K, Node*> map;
    int capacity, count;
    Node* head;
    Node* tail;

    void deleteNode(Node* node) {
        if (!node || !node->prev || !node->next)
            return;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = nullptr;
        node->next = nullptr;
    }

    void addToHead(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

public:
    LRUCache(int capacity) : capacity(capacity), count(0) {
        head = new Node(K{}, V{});
        tail = new Node(K{}, V{});
        head->next = tail;
        tail->prev = head;
    }

    V get(K key) {
        if (map.count(key)) {
            Node* node = map[key];
            V value = node->val;
            deleteNode(node);
            addToHead(node);
            return value;
        }
        return V{};  // Default value if not found
    }

    void put(K key, V value) {
        if (map.count(key)) {
            Node* node = map[key];
            node->val = value;
            deleteNode(node);
            addToHead(node);
        } else {
            Node* node = new Node(key, value);
            if (count < capacity) {
                count++;
            } else {
                Node* nodeToDelete = tail->prev;
                map.erase(nodeToDelete->key);
                deleteNode(nodeToDelete);
                delete nodeToDelete;
            }
            addToHead(node);
            map[key] = node;
        }
    }

    bool del(K key) {
        if (!map.count(key)) {
            return false;
        }
        Node* to_remove = map[key];
        deleteNode(to_remove);
        delete to_remove;
        map.erase(key);
        return true;
    }

    ~LRUCache() {
        // Free all nodes
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

int main() {
    LRUCache<string, int> cache(2);

    cache.put("one", 1);
    cache.put("two", 2);
    cout << cache.get("one") << endl;  // 1

    cache.put("three", 3);             // evicts "two"
    cout << cache.get("two") << endl;  // 0 (default int)

    cache.put("four", 4);                // evicts "one"
    cout << cache.get("one") << endl;    // 0 (default int)
    cout << cache.get("three") << endl;  // 3
    cout << cache.get("four") << endl;   // 4
}
