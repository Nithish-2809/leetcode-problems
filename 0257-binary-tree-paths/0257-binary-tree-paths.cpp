void treePaths(TreeNode *root, string s, vector<string>& ans) {
    if(root == NULL) return;

    if(s == "") {
        s = to_string(root->val);
    }
    else {
        s += "->" + to_string(root->val);
    }

    if(root->left == NULL && root->right == NULL) {
        ans.push_back(s);
        return;
    }

    treePaths(root->left, s, ans);
    treePaths(root->right, s, ans);
}

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        treePaths(root, "", ans);

        return ans;
    }
};