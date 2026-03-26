class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            value = v;
            next = prev = NULL;
        }
    };

    Node* head;
    Node* tail;
    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }


    void insertAfterHead(Node* node) {
        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        int val = node->value;

        deleteNode(node);
        insertAfterHead(node);

        return val;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            deleteNode(node);
            mp.erase(key);
        }

        if(mp.size() == cap) {
            Node* lru = tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
        }

        Node* newNode = new Node(key, value);
        insertAfterHead(newNode);
        mp[key] = newNode;
    }
};