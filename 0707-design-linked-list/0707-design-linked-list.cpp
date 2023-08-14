// class Node {
//     public:
//     int val;
//     Node* next;
//     Node(){
//         this->val = 0;
//         this->next = NULL;
//     }
//     Node(int x){
//         this->val = x;
//     }
// };
// class MyLinkedList {
//     Node *head;
//     int size;
// public:
//     MyLinkedList() {
//         head = NULL;
//         size = 0;
//     }
    
//     int get(int index) {
//         if(index>=size){
//             return -1;
//         }
//         Node* cur = head;
//         int i=0;
//         while(i!=index){
//             cur=cur->next;
//             i++;
//         }
//         return cur->val;
//     }
    
//     void addAtHead(int val) {
//         Node* newHead = new Node(val);
//         newHead->next = head;
//         head = newHead;
//         size++;
//         return;
//     }
    
//     void addAtTail(int val) {
//         addAtIndex(size,val);
//     }
    
//     void addAtIndex(int index, int val) {
//         if(index>size){
//             return;
//         }
//         if(index==0){
//             addAtHead(val);
//             return;
//         }
//         int i=0;
//         Node* cur = head;
//         while(i<index-1){
//             cur=cur->next;
//             i++;
//         }
//         Node* temp = cur->next;
//         cur->next = new Node(val);
//         cur->next->next = temp;
//         size++;
//         return;
        
//     }
    
//     void deleteAtIndex(int index) {
//         if(index>=size) return;
//         Node* cur=head;
//         if(index==0){
//             head = head->next;
//             return;
//         }
//         int i=0;
//         while(i!=index-1){
//             cur=cur->next;
//             i++;
//         }
//         cur->next =  cur->next->next;
//         size--;
//         return;
//     }
// };

// /**
//  * Your MyLinkedList object will be instantiated and called as such:
//  * MyLinkedList* obj = new MyLinkedList();
//  * int param_1 = obj->get(index);
//  * obj->addAtHead(val);
//  * obj->addAtTail(val);
//  * obj->addAtIndex(index,val);
//  * obj->deleteAtIndex(index);
//  */
class Node {
public:
    int val;
    Node* next;
    Node(){
        this->val = 0;
        this->next = NULL;
    }
    Node(int x){
        this->val = x;
        this->next = NULL;
    }
};

class MyLinkedList {
    Node *head;
    int size;
public:
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index >= size) {
            return -1;
        }
        Node* cur = head;
        int i = 0;
        while(i < index) {
            cur = cur->next;
            i++;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node* newHead = new Node(val);
        newHead->next = head;
        head = newHead;
        size++;
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) {
            return;
        }
        if(index == 0) {
            addAtHead(val);
            return;
        }
        int i = 0;
        Node* cur = head;
        while(i < index - 1) {
            cur = cur->next;
            i++;
        }
        Node* temp = cur->next;
        cur->next = new Node(val);
        cur->next->next = temp;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) {
            return;
        }
        Node* cur = head;
        if(index == 0) {
            head = head->next;
            delete cur;
            size--;
            return;
        }
        int i = 0;
        while(i < index - 1) {
            cur = cur->next;
            i++;
        }
        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;
        size--;
    }
};
