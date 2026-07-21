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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1=0,num2=0;
        ListNode*temp1=l1->next;
        ListNode*temp2=l2->next;
        ListNode*res= new ListNode((l1->val+l2->val)%10);
        ListNode*prev=res;
        int rem=(l1->val+l2->val)/10;
        while(temp1!=NULL&&temp2!=NULL){
              ListNode*newnode=new ListNode(((temp1->val+temp2->val)%10+rem)%10);
              rem=(temp1->val+temp2->val+rem)/10;
              prev->next=newnode;
              prev=prev->next;

              
              temp1=temp1->next;
              temp2=temp2->next;
              
        }
        while(temp1!=NULL){
            ListNode*newnode=new ListNode((temp1->val+rem)%10);
              rem=(temp1->val+rem)/10;
              prev->next=newnode;
              prev=prev->next;

              
              temp1=temp1->next;
             
        }
        while(temp2!=NULL){
            ListNode*newnode=new ListNode((temp2->val+rem)%10);
              rem=(temp2->val+rem)/10;
              prev->next=newnode;
              prev=prev->next;

              
              temp2=temp2->next;
             
        }
        if(rem!=0){
           ListNode*newnode=new ListNode(1);
           prev->next=newnode; 
        }
        
        
    return res;}
};