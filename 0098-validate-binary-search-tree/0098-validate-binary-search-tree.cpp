bool checkValidity(TreeNode *root,long long mini,long long maxi) {
    if(root==NULL) return true;

    if(root->val >= maxi || root->val <= mini) return false;

    return checkValidity(root->left, mini, root->val) &&
           checkValidity(root->right, root->val, maxi);
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {

        return checkValidity(root, LLONG_MIN, LLONG_MAX);
    }
};