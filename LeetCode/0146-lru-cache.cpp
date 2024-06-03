#include <unordered_map>
using std::unordered_map;
// https://en.cppreference.com/w/cpp/container/unordered_map

struct Node {
    int key, value;
    Node* prev, * next;
    Node() : key(0), value(0), prev(nullptr), next(nullptr) {}
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    Node(int k, int v, Node* p, Node* n) : key(k), value(v), prev(p), next(n) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> map;
    Node lru, mru;
    int size;
public:
    LRUCache(int capacity) {
        lru.next = &mru;
        mru.prev = &lru;
        size = capacity;
    }

    int get(int key) {
        if (map.find(key) == map.end())
            return -1;
        Node* node = map.at(key);
        remove(node);
        insert(node);
        return node->value;
    }

    void put(int key, int value) {
        Node* node;
        if (map.find(key) == map.end()) {
            node = new Node(key, value);
            map.insert({ key, node });
        }
        else {
            node = map.at(key);
            node->value = value;
            remove(node);
        }
        insert(node);

        if (map.size() > size) {
            node = lru.next;
            map.erase(node->key);
            remove(node);
            delete node;
        }
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = node->next = nullptr;
    }

    void insert(Node* node) {
        mru.prev->next = node;
        node->prev = mru.prev;
        mru.prev = node;
        node->next = &mru;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */