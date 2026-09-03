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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        int x=len-n-1;
        while(x>=0){
            x--;
            
            prev=curr;
            curr=curr->next;
            
        }if(prev==NULL)return curr->next;
        if(curr==NULL)prev->next=NULL;
        else prev->next=curr->next;
        
        return head;
    }
};