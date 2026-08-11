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

ListNode* reverseSinglyLinkedList(ListNode *head) {
    ListNode *prev = NULL;
    ListNode *curr = head;

    while(curr!=NULL) {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}


class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *temp = head;
        int maxi = INT_MIN;

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *secondHead = reverseSinglyLinkedList(slow);

        while(secondHead!=NULL) {
            int sum = temp->val + secondHead->val;
            maxi = max(maxi,sum);
            temp = temp->next;
            secondHead = secondHead->next;
        }
    return maxi;
    }
};