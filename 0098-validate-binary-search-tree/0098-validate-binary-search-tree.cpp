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
bool validateBinarySearchTree(TreeNode* root,long long minValue,long long maxValue) {
    if(root==NULL) return true;

    if(root->val<=minValue || root->val>=maxValue) return false;

    bool left = validateBinarySearchTree(root->left,minValue,root->val);
    bool right = validateBinarySearchTree(root->right,root->val,maxValue);

    return left&&right;
}



class Solution {
public:
    bool isValidBST(TreeNode* root) {
    
        return validateBinarySearchTree(root,LLONG_MIN,LLONG_MAX);
    }
};