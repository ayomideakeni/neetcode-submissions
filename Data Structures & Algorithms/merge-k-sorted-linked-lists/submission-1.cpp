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
    struct Compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

        ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        ListNode* dummy = new ListNode(0);
        ListNode* dTemp = dummy;

        for(auto* c : lists){
            if(c != nullptr) minHeap.push(c);
        }        
        
        while(!minHeap.empty()){
            ListNode* nNode = minHeap.top();
            minHeap.pop();
            dTemp->next = nNode;
            dTemp = dTemp->next;
            
            if(nNode->next != nullptr){
                minHeap.push(nNode->next);
            }
        
        }
            
            
        

        

        return dummy->next == nullptr ? nullptr : dummy->next;
    }
};