class Node{
    public:
    Node* next = nullptr ;
    Node* prev = nullptr ;
    string data;
    Node(string data){
        this->data = data;
    }
};
class BrowserHistory {
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        tail = head;
    }
    
    void visit(string url) {
    
        Node* newNode = new Node(url);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    
    }
    
    string back(int steps) {
        while(steps-- &&  tail != head){
            tail = tail->prev;
        }
        return tail->data;
    }
    
    string forward(int steps) {
        while(steps-- && tail->next){
            tail = tail->next;
        }
        return tail->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */