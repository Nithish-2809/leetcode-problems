
class Solution {
public:
    TreeNode* createTree(vector<int>& preorder, int& i, int bound) {
        if (i == preorder.size() || preorder[i] > bound)
            return nullptr;

        TreeNode* newNode = new TreeNode(preorder[i]);
        i++;

        newNode->left = createTree(preorder, i, newNode->val);
        newNode->right = createTree(preorder, i, bound);

        return newNode;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return createTree(preorder, i, INT_MAX);
    }
};
