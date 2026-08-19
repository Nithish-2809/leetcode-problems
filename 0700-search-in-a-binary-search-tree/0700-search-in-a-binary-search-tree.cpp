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

TreeNode* searchNode(TreeNode* root,int val) {
    if(root==NULL) return NULL;
    if(root->val==val) return root;

    TreeNode *left = searchNode(root->left,val);
    TreeNode *right = searchNode(root->right,val);

    if(left==NULL) return right;

    return left;
}

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return searchNode(root,val);
    }
};