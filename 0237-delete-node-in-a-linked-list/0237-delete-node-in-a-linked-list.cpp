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
    void deleteNode(ListNode* node) {
        if(node->next==NULL) {
            delete node;
            return;
        }

        ListNode* temp = node;
        ListNode* prev = NULL;
        
        while(temp!=NULL && temp->next!=NULL) {
            temp->val = temp->next->val;
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;

    }
};