
class Node{
    public:
        int key;
        int val;
        Node* next = nullptr;
        Node(int k,int v){
            key = k;
            val = v;
        }
};

class MyHashMap {
private:
   //vector<Node>vec(1000);
   Node* vec[1000];
   
public:

    MyHashMap(){
        for(int i=0;i<1000;++i){
            Node* dummy = new Node(0,0);
            vec[i] = dummy;
        }
        
    }
   
    void put(int key, int value) {

        if(vec[key%1000]->next){
            Node* temp = vec[key%1000]->next;
            while(temp){
                if(temp->key == key){
                    temp->val = value;
                    return;
                }
                if(temp->next == nullptr){
                    break;
                }
                temp = temp->next;
            }
            temp->next = new Node(key,value);
        }
        else {
            vec[key%1000]->next = new Node(key,value);
        }
    }
    
    int get(int key) {
        Node* temp = vec[key%1000]->next;
        while(temp){
            if(temp->key == key){
                return temp->val;
            }
            temp = temp->next;
        }
        return -1;
    }
    
    void remove(int key) {
        Node* curr = vec[key%1000]->next;
        Node* prev = vec[key%1000];
        Node* next = nullptr;

        while(curr){
            next = curr->next;
            if(curr->key == key){
                prev->next = next;
                return;
            }
            prev = curr;
            curr = next;
            
        }
    }
};