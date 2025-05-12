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
        ListNode *detectCycle(ListNode *head) {
            if(head == NULL || head->next == NULL)
                return NULL;
    
            ListNode* slow = head;
            ListNode* fast = head;
    
            // Step 1: Detect if a cycle exists
            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
    
                if(slow == fast) {
                    // Step 2: Find the starting point of the cycle
                    ListNode* entry = head;
                    while(entry != slow) {
                        entry = entry->next;
                        slow = slow->next;
                    }
                    return entry;
                }
            }
    
            return NULL; // No cycle
        }
    };
    