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
ListNode* middle(ListNode*head){
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode*merge(ListNode*l1,ListNode*l2){
    ListNode*res=new ListNode(-1);
    ListNode*reshead=res;
    
    while(l1!=NULL&&l2!=NULL){
        if(l1->val<l2->val){
            res->next=l1;
            l1=l1->next;
        }
        else{
            res->next=l2;
            l2=l2->next;
        }
        res=res->next;
    }
    while(l1!=NULL){
        res->next=l1;
        l1=l1->next;
        res=res->next;
    }
    while(l2!=NULL){
        res->next=l2;
        l2=l2->next;
        res=res->next;
    }
    return reshead->next;
}
ListNode*mergesort(ListNode*head){
    if(head==NULL||head->next==NULL)return head;
    ListNode* mid=middle(head);
    ListNode* right=mid->next;
    mid->next=NULL;
    ListNode* left=mergesort(head);
    ListNode*r=mergesort(right);
    return merge(left,r);
    
}
    ListNode* sortList(ListNode* head) {
        if(head==NULL)return NULL;
        return mergesort(head);
    }
};