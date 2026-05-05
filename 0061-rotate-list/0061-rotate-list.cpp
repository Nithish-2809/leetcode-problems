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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *temp = head;
        
        int n=1;
        while(temp->next!=NULL) {
            n++;
            temp = temp->next;
        }
        k = k%n;
        temp->next = head;
        temp = head;
        int z = n-k-1;

        while(z--) {
            temp = temp->next;
        }

        ListNode *newHead = temp->next;

        temp->next = NULL;

        return newHead;

    }
};