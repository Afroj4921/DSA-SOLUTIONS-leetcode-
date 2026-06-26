struct Node{
    int key, val, cnt;
    Node *next;
    Node *prev;
    Node(int k, int v){
        key = k;
        val = v;
        cnt = 1;
    }
};

struct List{
    int size; 
    Node *head;
    Node *tail;
    List(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    //add a node in front
    void addFront(Node* node){
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    // to remove a node
    void removeNode(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        size--;
    }
};

class LFUCache {
private:
    map<int, Node*> keyNode;
    map<int, List*> freq;
    int maxSizeCache;
    int minFreq, currSize;

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        currSize = 0;
    }
    void updateFreqListMap(Node* node){

        keyNode.erase(node->key);
        freq[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freq[node->cnt]->size == 0){
            minFreq++;
        }
        List* nextHigherFreq;
        if(freq.find(node->cnt + 1) != freq.end()){
            nextHigherFreq = freq[node->cnt + 1];
        }
        else{
            nextHigherFreq = new List();
        }
        node->cnt++;
        nextHigherFreq->addFront(node);
        freq[node->cnt] = nextHigherFreq;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int val = node->val;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0){
            return;
        }

        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);
        } else{
            if(currSize == maxSizeCache){
                List* list = freq[minFreq];
                keyNode.erase(list->tail->prev->key);
                freq[minFreq]->removeNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;

            List* listFreq = new List();
            if(freq.find(minFreq) != freq.end()){
                listFreq = freq[minFreq];
            }

            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freq[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */