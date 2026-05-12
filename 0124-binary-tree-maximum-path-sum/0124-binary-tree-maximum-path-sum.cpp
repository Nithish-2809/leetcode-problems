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

int findPath(TreeNode* root, int &maxi) {
    if(root==NULL) return 0;

    int lSum = max(0,findPath(root->left,maxi));
    int rSum = max(0,findPath(root->right,maxi));
    
    maxi = max(maxi,root->val+lSum+rSum);

    return root->val + max(lSum,rSum);
    
}




class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

        findPath(root,maxi);

        return maxi;
    }
};