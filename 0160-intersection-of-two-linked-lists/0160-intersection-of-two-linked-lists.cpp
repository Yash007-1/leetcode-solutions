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
        auto st=headA;
        while(headB!=NULL){
        while(headA!=NULL){
            if(headA==headB)return headA;
            headA=headA->next;
        }
        headB=headB->next;
        headA=st;}
        return NULL;
    }
};