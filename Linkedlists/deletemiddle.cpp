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
        ListNode* deleteMiddle(ListNode* head) {
            ListNode* temp1=head;
            ListNode* temp2=head;
            ListNode* prev=NULL;
            if(head==NULL||head->next==NULL){
                return NULL;
            }
    
            while(temp2->next!=NULL&&temp2->next->next!=NULL){
                prev=temp1;
                temp1=temp1->next;
                temp2=temp2->next->next;
            }
            if(temp2->next!=NULL&&temp2->next->next==NULL){
                prev=temp1;
                temp1=temp1->next;
            }
            if(temp1==head){
                head=head->next;
                return head;
            }
            prev->next=temp1->next;
            return head;
        }
    };