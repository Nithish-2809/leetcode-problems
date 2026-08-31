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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<ListNode*>criticalPoints;
        ListNode *prev = head;
        ListNode *temp = head;
        int minDist = INT_MAX;
        unordered_map<ListNode*,int>mp;

        int index = 1;
        while(temp!=NULL) {
            mp[temp] = index;
            index++;
            temp = temp->next;
        }

        temp = head->next;

        while(temp->next!=NULL) {
            ListNode *nextNode = temp->next;

            if(temp->val<prev->val && temp->val<nextNode->val) {
                criticalPoints.push_back(temp);
            }
            else if(temp->val>prev->val && temp->val>nextNode->val) {
                criticalPoints.push_back(temp);
            }
            prev = temp;
            temp = temp->next;
        }

        int n = criticalPoints.size();

        for(int i=0;i<n-1;i++) {
            minDist = min(minDist,mp[criticalPoints[i+1]]-mp[criticalPoints[i]]);
        }

        if(minDist==INT_MAX) return {-1,-1};

        
        int maxDist = mp[criticalPoints[n-1]]-mp[criticalPoints[0]];

      return {minDist,maxDist};
    }
};