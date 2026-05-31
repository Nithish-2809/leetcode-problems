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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; 
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
       priority_queue<ListNode*, vector<ListNode*>, cmp> minH;

        for (auto node : lists) {
            if (node)
                minH.push(node);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minH.empty()) {
            ListNode* curr = minH.top();
            minH.pop();

            tail->next = curr;
            tail = tail->next;

            if (curr->next)
                minH.push(curr->next);
        }

        return dummy.next;
    }
};