class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessDummy = new ListNode(0);
        ListNode* greaterDummy = new ListNode(0);

        ListNode* lessTail = lessDummy;
        ListNode* greaterTail = greaterDummy;

        ListNode* curr = head;

        while (curr) {
            if (curr->val < x) {
                lessTail->next = curr;
                lessTail = curr;
            } else {
                greaterTail->next = curr;
                greaterTail = curr;
            }
            curr = curr->next;
        }

        greaterTail->next = NULL;
        lessTail->next = greaterDummy->next;

        return lessDummy->next;
    }
};