class Solution {
public:

    void findParentNode(TreeNode *root,
                        unordered_map<TreeNode*,TreeNode*>& parentMap) {

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode *node = q.front();
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

    void findNode(TreeNode *root,int start,TreeNode* &node) {

        if(root==NULL || node!=NULL) return;

        if(root->val == start) {
            node = root;
            return;
        }

        findNode(root->left,start,node);
        findNode(root->right,start,node);
    }

    int findBurningTime(TreeNode *node,
                        unordered_map<TreeNode*,TreeNode*>& parentMap) {

        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;

        q.push(node);
        visited[node] = true;

        int time = 0;

        while(!q.empty()) {

            int size = q.size();
            bool burned = false;

            for(int i=0;i<size;i++) {

                TreeNode *curr = q.front();
                q.pop();

                
                if(curr->left && !visited[curr->left]) {
                    burned = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }

                
                if(curr->right && !visited[curr->right]) {
                    burned = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }

                
                if(parentMap[curr] && !visited[parentMap[curr]]) {
                    burned = true;
                    visited[parentMap[curr]] = true;
                    q.push(parentMap[curr]);
                }
            }

            if(burned) time++;
        }

        return time;
    }

    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*,TreeNode*> parentMap;

        findParentNode(root,parentMap);

        TreeNode *node = NULL;

        findNode(root,start,node);

        return findBurningTime(node,parentMap);
    }
};