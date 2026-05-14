class Solution {
public:

    void findLeafPath(TreeNode* root, string &path, vector<string>& ans) {
        if(root == NULL) return;

        int len = path.length();

        path += to_string(root->val);

        if(root->left == NULL && root->right == NULL) {
            ans.push_back(path);

            path.erase(len); 
            return;
        }

        path += "->";

        findLeafPath(root->left, path, ans);
        findLeafPath(root->right, path, ans);

        path.erase(len);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";

        findLeafPath(root, path, ans);

        return ans;
    }
};