#include <unordered_map>
using std::unordered_map;
// https://en.cppreference.com/w/cpp/container/unordered_map

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map = { {nullptr, nullptr} };
        Node* node, *p = head;
        while (p)
        {
            node = new Node(p->val);
            map.insert({ p, node });
            p = p->next;
        }
        p = head;
        while (p)
        {
            node = map.at(p);
            node->next = map.at(p->next);
            node->random = map.at(p->random);
            p = p->next;
        }
        return map.at(head);
    }
};