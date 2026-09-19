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


ListNode *reverseNodes(ListNode *head) {
    if(head==NULL || head->next==NULL) return head;

    ListNode *lastNode = head->next;
    head->next = NULL;
    lastNode->next = head;

    return lastNode;
}


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp = head;

        if(temp == NULL || temp->next == NULL) return temp;

        ListNode *linkedListHead = head->next;
        ListNode *prevTail = NULL;

        while(temp != NULL && temp->next != NULL) {

            ListNode *nexthead = temp->next->next;

            temp->next->next = NULL;

            ListNode *newHead = reverseNodes(temp);

            if(prevTail != NULL) {
                prevTail->next = newHead;
            }

            newHead->next->next = nexthead;

            prevTail = newHead->next;

            temp = nexthead;
        }

        return linkedListHead;
    }
};