class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> m;
    
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // too add node right after head
    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* node) {
        Node* front = node->next;
        Node* back = node->prev;
        front->prev = back;
        back->next = front;
    }
    
    int get(int key_) {

        if(m.find(key_) != m.end()) {
            Node* resNode = m[key_];
            int res = resNode->val;

            m.erase(key_);

            deleteNode(resNode);
            addNode(resNode);

            m[key_] = head->next;
            return res;
        }

        // if not found in mpp
        return -1;
    }
    
    void put(int key_, int value) {
        
        // if already exists in map then update the value
        if(m.find(key_) != m.end()) {
            Node* resNode = m[key_];
            m.erase(key_);
            deleteNode(resNode);   
        }

        if(m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        // insert new node at the front after head
        addNode(new Node(key_, value));
        m[key_] = head->next; // update the map
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */