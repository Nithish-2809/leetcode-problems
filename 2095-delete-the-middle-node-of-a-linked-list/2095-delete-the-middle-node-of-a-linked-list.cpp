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
        if(head==NULL || head->next==NULL) return NULL;
        if(head->next->next==NULL) {
            head->next = NULL;
            return head;
        }

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast->next!=NULL && fast->next->next!=NULL && fast->next->next->next!= NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *delNode = slow->next;
        slow->next = delNode->next;

        delete delNode;

        return head;
    }
};