class LRUCache {
    // Node represents one cache entry: its key and value, plus pointers to form a doubly linked list
    struct Node{
        int key, value;
        Node *prev, *next;
        Node(int k, int v){
            this->key = k;
            this->value = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    
    unordered_map<int, Node*> mpp;    // key -> its Node (for O(1) lookup of value/position)
    int capacity;                      // max number of keys the cache can hold
    
    // dummy head/tail nodes -> simplify insert/remove logic by avoiding null-pointer edge cases
    // list ordering: head side = most recently used, tail side = least recently used
    Node *head = new Node(-1,-1), *tail = new Node(-1,-1);
    
public:
    LRUCache(int capacity) {
        // link the dummy head and tail together -> represents an empty list initially
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }
    
    // splices a node out of the list using its own prev/next pointers -> O(1), no searching needed
    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    // inserts a node right after the dummy head -> marks it as "most recently used"
    void insertAfterHead(Node* node){
        Node* currAfterHead = head->next;
        head->next = node;
        node->next = currAfterHead;
        node->prev = head;
        currAfterHead->prev = node;
    }

    int get(int key) {
        // key not found -> return -1 as required
        if(mpp.find(key) == mpp.end()) return -1;
        
        Node* node = mpp[key];
        
        // accessing a key counts as a "use" -> move it to the most-recently-used position
        deleteNode(node);
        insertAfterHead(node);
        
        return node->value;
    }
    
    void put(int key, int val) {
        // CASE A: key already exists -> just update its value, and move it to most-recently-used
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->value = val;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            // CASE B: key is new
            
            // if the cache is already full, evict the least recently used key
            if(mpp.size() == capacity){
                // tail->prev always gives the STALEST node -> since insertAfterHead 
                // always pushes new/touched nodes toward the head, untouched ones drift toward the tail
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            
            // create the new node and insert it at the most-recently-used position
            Node* node = new Node(key, val);
            mpp[key] = node;
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */