/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void findParent(TreeNode* root,
                unordered_map<TreeNode*,TreeNode*>& parentMap) {

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if(node->left) {
            parentMap[node->left] = node;
            q.push(node->left);
        }

        if(node->right) {
            parentMap[node->right] = node;
            q.push(node->right);
        }
    }
}

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*,TreeNode*> parentMap;
        findParent(root, parentMap);

        unordered_map<TreeNode*,bool> visited;

        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int dist = 0;

        while(!q.empty()) {

            int size = q.size();

            if(dist == k) break;

            dist++;

            for(int i=0; i<size; i++) {

                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }

                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }

                if(parentMap[node] && !visited[parentMap[node]]) {
                    q.push(parentMap[node]);
                    visited[parentMap[node]] = true;
                }
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};