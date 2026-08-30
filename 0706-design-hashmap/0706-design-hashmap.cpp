class MyHashMap {
public:
    struct Node{
        int key;
        int val;
        Node* next;

        Node(int key,int val){
            this->key=key;
            this->val=val;
            this->next=nullptr;
        }
    };

    static const int SIZE =1000;
    Node* bucket[SIZE];
    int hash(int key){
        return key%1000;
    }
    MyHashMap() {
        for(int i=0;i<SIZE;i++){
            bucket[i]=nullptr;
        }
    }
    
    void put(int key, int value) {
        int idx=hash(key);
        if(bucket[idx]==nullptr){
            bucket[idx]=new Node(key,value);
            return;
        }
        Node* curr=bucket[idx];

        while(curr!=nullptr){
            if(curr->key==key){
                curr->val=value;
                return;
            }

            if(curr->next==nullptr){
                break;
            }

            curr=curr->next;
        }
        curr->next=new Node(key,value);
    }
    
    int get(int key) {
        int idx=hash(key);
        Node* curr=bucket[idx];

        while(curr!=nullptr){
            if(curr->key==key){
                return curr->val;
            }
            curr=curr->next;
        }

        return -1;
    }
    
    void remove(int key) {
        int idx=hash(key);
        Node* curr=bucket[idx];
        Node* prev=nullptr;

        while(curr!=nullptr){
            if(curr->key==key){
                if(prev==nullptr){
                    bucket[idx]=curr->next;
                }else{
                    prev->next=curr->next;
                }

               delete curr;
               return;


            }
             prev=curr;
            curr=curr->next;
        }


    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */