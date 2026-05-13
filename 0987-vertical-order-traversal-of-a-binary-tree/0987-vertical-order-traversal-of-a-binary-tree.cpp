/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

void preorder(TreeNode* root, int vertical, int level,
              map<int, vector<pair<int,int>>>& mp) {

    if(root == NULL) return;

    mp[vertical].push_back({level, root->val});

    preorder(root->left, vertical - 1, level + 1, mp);
    preorder(root->right, vertical + 1, level + 1, mp);
}

class Solution {
public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, vector<pair<int,int>>> mp;

        preorder(root, 0, 0, mp);

        vector<vector<int>> ans;

        for(auto it : mp) {

            auto vec = it.second;

            sort(vec.begin(), vec.end());

            vector<int> temp;

            for(auto x : vec) {
                temp.push_back(x.second);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};