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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lessDummy = new ListNode(0);
        ListNode *lessTail = lessDummy;
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        ListNode *temp = head;

        while(temp!=NULL) {
            if(temp->val<x) {
                lessTail->next = temp;
                lessTail = lessTail->next;
            }
            else {
                tail->next = temp;
                tail = tail->next;
            }

            temp = temp->next;
        }

        tail->next = NULL;          
        lessTail->next = dummy->next;


        return lessDummy->next;

    }
};