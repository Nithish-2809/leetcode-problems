/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>st;
        int n = descriptions.size();

        for(auto d : descriptions) {
            int parentNode = d[0];
            int childNode = d[1];
            int isLeft = d[2];

            if(!mp.count(parentNode)) {
                mp[parentNode] = new TreeNode(parentNode);
            }

            if(!mp.count(childNode)) {
                mp[childNode] = new TreeNode(childNode);
            }

            if(isLeft) {
                mp[parentNode]->left = mp[childNode];
            }
            else {
                mp[parentNode]->right = mp[childNode];
            }

            st.insert(childNode);
        }

        for(auto it : mp) {
            if(st.find(it.first)==st.end()) return it.second;
        }

    return NULL;
    }
};