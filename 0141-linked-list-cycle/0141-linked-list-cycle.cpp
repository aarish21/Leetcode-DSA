/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        unordered_map<ListNode *,int> m;
        while(head->next!=NULL){
            m[head]++;
            if(m.count(head->next)>0){
                return true;
            }
            head = head->next;
        }
        return false;
    }
};