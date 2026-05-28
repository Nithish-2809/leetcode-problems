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

class Solution {
public:

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int,int>& mp) {

        // Base case
        if(preStart > preEnd || inStart > inEnd)
            return NULL;

        // Root from preorder
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Root index in inorder
        int inRoot = mp[root->val];

        // Number of nodes in left subtree
        int numsLeft = inRoot - inStart;

        // Build left subtree
        root->left = build(preorder,
                           preStart + 1,
                           preStart + numsLeft,
                           inorder,
                           inStart,
                           inRoot - 1,
                           mp);

        // Build right subtree
        root->right = build(preorder,
                            preStart + numsLeft + 1,
                            preEnd,
                            inorder,
                            inRoot + 1,
                            inEnd,
                            mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int,int> mp;

        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        TreeNode* root = build(preorder, 0, preorder.size()-1,
                     inorder, 0, inorder.size()-1,
                     mp);

        return root;
    }
};