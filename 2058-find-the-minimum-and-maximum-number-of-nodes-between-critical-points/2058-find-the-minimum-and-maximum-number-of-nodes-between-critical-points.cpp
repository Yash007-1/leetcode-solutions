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
        int n=0;
        ListNode*temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        vector<int>ans={-1,-1};
        if(n<4)return ans;
        vector<int>criti;
        vector<int>maxi;
        int i=1;
        while(curr->next!=NULL){
            NExt=curr->next;
            if((curr->val<NExt->val&&curr->val<prev->val)||(curr->val>NExt->val&&curr->val>prev->val)){
                 criti.push_back(i);
            }
            i++;
            prev=curr;
            curr=NExt;
            
        }
        int x=criti.size();
        if(x<2)return ans;
        ans[1]=criti[x-1]-criti[0];
        int mindis=INT_MAX;
        for(int j=1;j<x;j++){
            mindis=min(mindis,criti[j]-criti[j-1]);
        }
        ans[0]=mindis;
        return    ans; }
};