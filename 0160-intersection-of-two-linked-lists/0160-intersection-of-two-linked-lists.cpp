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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return NULL;
        unordered_map<ListNode*,int> m;
        while(headA){
            m[headA]++;
            headA = headA->next;
        }
		while(headB){
            if(m[headB]>0)
                return headB;
             headB = headB->next;
        }
        return NULL;
    }
};