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
    int maxSum;

int solve(TreeNode *node) {
    if(node==NULL) return 0;

    int l = solve(node->left);
    int r = solve(node->right);

    int niche_ans_milgaya = node->val + l + r;
    int koi_ek_accha_mila = node->val + max(l,r);
    int only_root_accha = node->val;

    maxSum = max({maxSum,niche_ans_milgaya,koi_ek_accha_mila,only_root_accha});

    return max(only_root_accha,koi_ek_accha_mila);
}

public:
    int maxPathSum(TreeNode* root) {
        maxSum =  INT_MIN;

        solve(root);

    return maxSum;
    }
};