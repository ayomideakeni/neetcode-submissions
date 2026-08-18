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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;
        int n = 0;
        
        while(start != nullptr){
            start = start->next;
            ++n;
        }

        
        int kGroups = n/k;
        ListNode* dummy = new ListNode(0);
        ListNode* dTail = dummy;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        for(int i = 0; i < kGroups; ++i){
            for(int j = 0; j < k; ++j){
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            dTail->next = prev;
            prev = nullptr;
            while(dTail->next != nullptr){
                dTail = dTail->next;
            }
        }
        
        dTail->next = curr;
        head = dummy->next;

        
        return head;
        
    }
};
