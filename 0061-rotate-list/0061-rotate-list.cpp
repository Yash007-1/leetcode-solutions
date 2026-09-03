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
    ListNode* reverse(ListNode* head) {
        if(head==NULL) return head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* Next=NULL;
        while(curr!=NULL){
            Next=curr->next;
            curr->next=prev;
             prev=curr;
             curr=Next;
             

             
            
        }
        
        head=prev;
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return NULL;
        
        int len=0;
        ListNode*temp=head;
        while(temp!=NULL){
          len++;
          temp=temp->next;  
        }
        k=k%len;
        if(k==0)return head;
        head=reverse(head);
        temp=head;
        for(int i=0;i<k-1;i++){
              temp=temp->next;
        }
        ListNode*right=reverse(temp->next);
        temp->next=NULL;
        temp=reverse(head);
       head->next=right;
       head=temp;
       return head;
    }
};