#include <vector>
using namespace std;

class Node{
    public:
        int val;
        Node* next = nullptr;
        Node(int val){
            this->val = val;
            next = nullptr;
        }
};
class MyHashSet {
public:
    vector<Node*>arr;
    MyHashSet() {
        arr.resize(1000);
        for(int i = 0;i < 1000;i++){
            Node* dummy =  new Node(0);
            arr[i] = dummy;
        }
    }
    
    void add(int key) {
        Node* temp = arr[key%1000];

        while(temp->next){
            if(temp->next->val == key) return;
            temp = temp->next;
            
        }
        temp->next = new Node(key);
    }
    
    void remove(int key) {
        Node* temp = arr[key%1000];
        while(temp->next){
            if(temp->next->val == key){
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
    }
    
    bool contains(int key) {
        Node* temp = arr[key%1000];
        while(temp->next){
            if(temp->next->val == key) return true;
            temp = temp->next;
        }
        return false;
    }
};