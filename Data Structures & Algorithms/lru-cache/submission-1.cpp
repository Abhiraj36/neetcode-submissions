#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, value;
    Node *prev, *next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);  // dummy head
        tail = new Node(-1, -1);  // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    // Insert node next to head (MRU position)
    void addNode(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    // Remove a node from the DLL
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        int val = node->value;

        // Move the accessed node to MRU position
        deleteNode(node);
        addNode(node);

        return val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* oldNode = mp[key];
            deleteNode(oldNode);
            mp.erase(key);
            delete oldNode;
        }

        if (mp.size() == cap) {
            // Remove LRU from tail->prev
            Node* lru = tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

