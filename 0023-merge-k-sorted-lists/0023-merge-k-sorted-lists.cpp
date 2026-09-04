struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

void traverse(ListNode* head,
              priority_queue<ListNode*, vector<ListNode*>, cmp>& q) {
    ListNode* temp = head;

    while (temp != NULL) {
        q.push(temp);
        temp = temp->next;
    }
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;

        for (auto head : lists) {
            traverse(head, q);
        }

        ListNode* dummyNode = new ListNode(-1);
        ListNode* tail = dummyNode;

        while (!q.empty()) {
            ListNode* node = q.top();
            q.pop();

            tail->next = node;
            tail = tail->next;
        }

        tail->next = nullptr;

        return dummyNode->next;
    }
};