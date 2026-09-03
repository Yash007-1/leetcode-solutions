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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        int i=1;
        ListNode*oddtail=head;
        ListNode*temp=head->next->next;
        ListNode*even_h=head->next;
        ListNode*eventail=head->next;
        while(temp!=NULL){
            if(i%2==0){
                eventail->next=temp;
                eventail=temp;
                
            }
            else {
                oddtail->next=temp;
                oddtail=temp;
            }
            temp=temp->next;
            i++;
        }
        eventail->next=NULL;
        oddtail->next=even_h;
        return head;
    }
};