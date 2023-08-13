class node{
    public:
       int val;
       node* next;

       node(int data){
           this->val = data;
           this->next = NULL;
       }
};

class MyLinkedList {
public:
    node* head;
    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        node* temp = head;
        int i = 0;
        while(temp != NULL && i < index){
            temp = temp->next;
            i++;
        }
        if(temp == NULL) return -1;
        return temp->val;
    }
    
    void addAtHead(int val) {
        node* newh = new node(val);
        if(head == NULL) {
            head = newh;
            return;
        }
        else{
            newh->next = head;
            head = newh;
        }
    }
    
    void addAtTail(int val) {
        node* newt = new node(val);
        if(head == NULL){
            head = newt;
            return;
        }
        else{
            node* t = head;
            while(t->next != NULL){
                t = t->next;
            }
            t->next = newt;
        }
    }
    
    void addAtIndex(int index, int val) {
        node* newn = new node(val);
        if(index == 0){
            newn->next = head;
            head = newn;
            return;
        }
        else{
            node* temp = head;
            int i = 0;
            while(temp != NULL && i < index - 1){
                temp = temp->next;
                i++;
            }
            if(temp == NULL) return;
            if(temp != NULL && temp->next == NULL){
                temp->next = newn;
                return;
            }
            if(i == index - 1){
                node* t = temp->next;
                temp->next = newn;
                newn->next = t;
            }
              
        }

    }
    
    void deleteAtIndex(int index) {
        node* temp = head;
        if(index == 0){
            head = head->next;
            return;
        }
        int i = 0;
        while(temp != NULL && i < index - 1){
            temp = temp->next;
            i++;
        }
        if(temp != NULL && temp->next != NULL && i == index - 1){
            temp->next = temp->next->next;
            return;
        }
        else{
            return;
        }
    }
};