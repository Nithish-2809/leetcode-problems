
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* tail = dummyNode;

        int carry = 0;

        while (temp1 != NULL || temp2 != NULL || carry != 0) {
            int sum = carry;

            if (temp1 != NULL) {
                sum += temp1->val;
                temp1 = temp1->next;
            }

            if (temp2 != NULL) {
                sum += temp2->val;
                temp2 = temp2->next;
            }

            int num = sum % 10;
                carry = sum / 10;

            tail->next = new ListNode(num);
            tail = tail->next;
        }

        return dummyNode->next;
    }
};
