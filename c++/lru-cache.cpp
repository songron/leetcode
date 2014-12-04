/* // https://oj.leetcode.com/problems/lru-cache/
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Solve method:
Data structures: use a double linked list and a hashmap.
*/

class LRUCache{
private:
    struct Node {
        int key;
        int value;
        Node *prev, *next;
        Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
    };
    unordered_map<int, Node*> mapper;
    Node *head, *tail;
    int capacity;

    void insert(Node *target) {
        target->prev = head;
        target->next = head->next;
        head->next->prev = target;
        head->next = target;
    }

    void split(Node *target) {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mapper.find(key) == mapper.end()) return -1;
        Node *target = mapper[key];
        if (target != head->next) {
            split(target);
            insert(target);
        }
        return target->value;
    }

    void set(int key, int value) {
        if (get(key) != -1) {  // the key already exist
            head->next->value = value;
            return ;
        }

        Node *tmp = NULL;
        if (mapper.size() == capacity) {
            tmp = tail->prev;
            split(tmp);
            mapper.erase(tmp->key);
            tmp->key = key;
            tmp->value = value;
        }
        else {
            tmp = new Node(key, value);
        }
        mapper[key] = tmp;

        insert(tmp);
    }
};
