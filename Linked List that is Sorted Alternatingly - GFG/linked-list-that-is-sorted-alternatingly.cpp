//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function
 Node* mergeList(Node* left,Node* right){
        if(left==NULL)
            return right; 
        if(right==NULL)
            return left;
        
        Node* ans=new Node(-1);
        Node* temp=ans;
        while(left!=NULL && right!=NULL){
            if(left->data < right->data){
                    temp->next=left; 
                    temp=left;
                    left=left->next;
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
            }
                // temp=temp->next;  
        }

        while(left){
            temp->next=left;
            temp=temp->next;
            left=left->next;
        }
        while(right){
            temp->next=right;
            temp=temp->next;
            right=right->next;
        }
        ans=ans->next;
        return ans;
    }
 Node* reverseList(Node* head) {
        if (head == NULL||head->next==NULL)
            return head;

        Node* nnode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return nnode;
    }
void sort(Node **head)
{
     // Code here
    
     Node *odd = *head;
     Node* even = odd->next;
     Node *t1 = even;
     Node* t2 = odd;
     
    while(even && even->next){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        if(odd)
        odd->next = NULL;  
        if(even)
      even->next = NULL;
     
     t1 = reverseList(t1);
   
    *head =  mergeList(t2,t1);;
      

}