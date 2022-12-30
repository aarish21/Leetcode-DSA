/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   ListNode *findmid(ListNode *head){
        ListNode *slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergeList(ListNode* left,ListNode* right){
        if(left==NULL)
            return right; 
        if(right==NULL)
            return left;
        
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(left!=NULL && right!=NULL){
            if(left->val < right->val){
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
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *mid=findmid(head);

        // while(fast!=NULL && fast->next!=NULL){
        //     fast=fast->next->next;
        //     mid=mid->next;
        // }
        ListNode *left=head;
        ListNode *right=mid->next;
        mid->next=NULL;
        
        left=sortList(left);
        right=sortList(right);

        ListNode* ans=mergeList(left,right);

        return ans;
    }
};