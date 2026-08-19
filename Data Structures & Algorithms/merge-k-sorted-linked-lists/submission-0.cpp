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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        priority_queue<int, vector<int>, greater<>> minHeap;
        ListNode* dummy = new ListNode(0);

        for(auto* c : lists){
            while(c != nullptr){
                minHeap.push(c->val);
                c = c->next;
            }
        }

        ListNode* dTemp = dummy;
        while(!minHeap.empty()){
            int num = minHeap.top();
            ListNode* nNode = new ListNode(num);
            dTemp->next = nNode;
            dTemp = dTemp->next;
            minHeap.pop();
            
        }

        return dummy->next == nullptr ? nullptr : dummy->next;
    }
};
