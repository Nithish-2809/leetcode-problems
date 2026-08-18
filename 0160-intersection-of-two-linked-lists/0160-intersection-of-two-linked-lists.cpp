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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;

        unordered_map<ListNode*,int>list1Nodes;

        while(temp1!=NULL) {
            list1Nodes[temp1]++;
            temp1 = temp1->next;
        }

        while(temp2!=NULL) {
            list1Nodes[temp2]++;
            if(list1Nodes[temp2]==2) return temp2;
            temp2 = temp2->next;
        }

    return NULL;
    }
};