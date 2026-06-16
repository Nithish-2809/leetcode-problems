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

 ListNode *findKthNode(ListNode *node, int k) {

    if(node == NULL) return NULL;

    while(--k && node != NULL) {
        node = node->next;
    }

    return node;
}

ListNode* reverseLinkedList(ListNode *head) {
    ListNode *prev = NULL;
    ListNode *curr = head;

    while(curr != NULL) {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
         if(head == NULL || head->next==NULL) return head;

        ListNode *temp = head;
        ListNode *prevLast = NULL;

        int k = 2;

        while(temp != NULL) {

            ListNode *kthNode = findKthNode(temp, k);

            
            if(kthNode == NULL) {
                if(prevLast != NULL)
                    prevLast->next = temp;
                break;
            }

            ListNode *nextNode = kthNode->next;
            kthNode->next = NULL;

            
            ListNode *newHead = reverseLinkedList(temp);

            
            if(temp == head) {
                head = newHead;
            }
            else {
                prevLast->next = newHead;
            }

            prevLast = temp;   
            temp = nextNode;
        }

        return head;
    }
};