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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*prev=head;
        ListNode*curr=head->next;
        ListNode*NExt=curr;
        // int n=0;
        // ListNode*temp=head;
        // while(temp!=NULL){
        //     n++;
        //     temp=temp->next;
        // }
        vector<int>ans={-1,-1};
        // if(n<4)return ans;
        // vector<int>criti;
        int first=-1;
        int last=-1;
       int mindis=INT_MAX;
        int i=1;
        while(curr!=NULL&&curr->next!=NULL){
            NExt=curr->next;
            if((curr->val<NExt->val&&curr->val<prev->val)||(curr->val>NExt->val&&curr->val>prev->val)){
                 if(first==-1)first=i;
                 else mindis=min(mindis,i-last);
                 last=i;
            }
            i++;
            prev=curr;
            curr=NExt;}
            
       if(mindis==INT_MAX)return ans;
        ans[1]=last-first;
        
        ans[0]=mindis;
        return    ans; }
};