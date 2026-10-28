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
    ListNode* sortList(ListNode* head) {
        vector<int>ans;
        ListNode *temp = head;
        ListNode *dummyNode = new ListNode(-1);
        ListNode *tail = dummyNode;

        while(temp!=NULL) {
            ans.push_back(temp->val);
            temp = temp->next;
        }

        sort(ans.begin(),ans.end());

        for(auto it : ans) {
            ListNode *newNode = new ListNode(it);

            tail->next = newNode;
            tail = newNode;
        } 

        tail->next = NULL;

    return dummyNode->next;
    }
};