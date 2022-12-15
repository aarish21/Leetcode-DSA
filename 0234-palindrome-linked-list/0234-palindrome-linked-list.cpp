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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL||head->next==NULL)
            return head;

        ListNode* nnode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return nnode;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return true;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast->next!=NULL&&fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        
        ListNode* temp = head;
        while(slow!=NULL){
            if(slow->val != temp->val)
                return false;
            
            temp = temp->next;
            slow = slow->next;
        }
        return true;
    }
};