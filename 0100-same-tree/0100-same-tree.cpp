class Solution {
public:
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
        if (r1 == NULL && r2 == NULL) return true;

        if (r1 == NULL || r2 == NULL) return false;

        return (r1->val == r2->val
        ) &&
               isSameTree(r1->left, r2->left) &&
               isSameTree(r1->right, r2->right);
    }
};