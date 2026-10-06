class Node {
public:
    pair<int,int> p;
    Node* next;
    Node* prev;

    Node(int key,int value) {
        p = {key,value};
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    Node* head;
    Node* tail;

    int capacity;
    int size;

    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = NULL;
        tail = NULL;
    }

    int get(int key) {
        Node* temp = head;

        while(temp != NULL) {
            if(temp->p.first == key) {

                int value = temp->p.second;

                // Move to front
                if(temp != head) {

                    if(temp == tail) {
                        tail = tail->prev;
                        tail->next = NULL;
                    }
                    else {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                    }

                    temp->next = head;
                    temp->prev = NULL;
                    head->prev = temp;
                    head = temp;
                }

                return value;
            }

            temp = temp->next;
        }

        return -1;
    }

    void put(int key, int value) {

        // Check if key already exists
        Node* temp = head;

        while(temp != NULL) {

            if(temp->p.first == key) {

                temp->p.second = value;

                // Move to front
                if(temp != head) {

                    if(temp == tail) {
                        tail = tail->prev;
                        tail->next = NULL;
                    }
                    else {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                    }

                    temp->next = head;
                    temp->prev = NULL;
                    head->prev = temp;
                    head = temp;
                }

                return;
            }

            temp = temp->next;
        }

        Node* newNode = new Node(key,value);

        if(head == NULL) {
            head = tail = newNode;
            size++;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;

        size++;

        if(size > capacity) {

            Node* delNode = tail;

            tail = tail->prev;

            if(tail) tail->next = NULL;

            delete delNode;

            size--;
        }
    }
};