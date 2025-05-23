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
        ListNode* reverseList(ListNode* head) {
            if (head == NULL)
                return NULL;
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* next = curr->next;
    
            while (curr->next != NULL) {
                curr->next = prev;
                prev = curr;
                curr = next;
                next = curr->next;
            }
            curr->next = prev;
            return curr;
        }
    
        void reorderList(ListNode* head) {
            if (head == NULL)
                return;
            ListNode* slow = head;
            ListNode* fast = head;
    
            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode* second = slow->next;
            slow->next = NULL; // <-- Important to disconnect!
            second = reverseList(second);
    
            ListNode* first = head;
            while (second != NULL) {
                ListNode* temp1 = first->next;
                ListNode* temp2 = second->next;
    
                first->next = second;
                second->next = temp1;
    
                first = temp1;
                second = temp2;
            }
        }
    };