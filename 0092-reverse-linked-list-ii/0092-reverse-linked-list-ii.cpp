class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode *temp = head;
        ListNode *prev = NULL;
        int index = 1;

        while (temp != NULL && index != left) {
            prev = temp;
            temp = temp->next;
            index++;
        }

        ListNode *start = temp;

        while (temp != NULL && index != right) {
            temp = temp->next;
            index++;
        }

        ListNode *continuation = temp->next;

        temp->next = NULL;

        ListNode *sublistHead = reverseSinglyLinkedList(start);

        if (prev != NULL) {
            prev->next = sublistHead;
        } else {
            head = sublistHead;
        }

        start->next = continuation;

        return head;
    }

    ListNode* reverseSinglyLinkedList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *temp = head;

        while (temp != NULL) {
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }
};