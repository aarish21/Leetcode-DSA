//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
     Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* cur = head;
        Node* forw = NULL;
        while(cur!=NULL){
            forw = cur->next;
            cur->next = prev;
            prev = cur;
            cur = forw;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head==NULL||head->next==NULL) return true;
        Node* slow = head;
        Node* fast = head;
         while(fast->next!=NULL&&fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverse(slow->next);
        slow = slow->next;
        
        Node* temp = head;
        
        while(slow!=NULL){
           
            if(temp->data!=slow->data) return false;
            slow = slow->next;
            temp = temp->next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends