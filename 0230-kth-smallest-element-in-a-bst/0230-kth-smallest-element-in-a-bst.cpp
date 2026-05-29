void inorder(TreeNode* root, int k, int &cnt, int &ans) {
    if(root == NULL) return;
    if(ans != INT_MAX) return;

    inorder(root->left, k, cnt, ans);

    cnt++;
    if(cnt == k) {
        ans = root->val;
        return;
    }

    inorder(root->right, k, cnt, ans);
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans = INT_MAX;

        inorder(root, k, cnt, ans);

        return ans;
    }
};