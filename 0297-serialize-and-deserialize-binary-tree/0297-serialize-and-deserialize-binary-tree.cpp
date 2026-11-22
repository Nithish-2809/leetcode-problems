/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();

            if (currNode == NULL) {
                s += "#,";
            } else {
                s += to_string(currNode->val) + ",";

                q.push(currNode->left);
                q.push(currNode->right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return NULL;

        int n = data.length();
        int i = 0;

        // Extract root value
        string num = "";

        while (i < n && data[i] != ',') {
            num += data[i];
            i++;
        }
        i++;

        TreeNode* root = new TreeNode(stoi(num));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();

            // Left child
            string leftVal = "";

            while (i < n && data[i] != ',') {
                leftVal += data[i];
                i++;
            }
            i++;

            if (leftVal != "#") {
                TreeNode* leftNode = new TreeNode(stoi(leftVal));
                currNode->left = leftNode;
                q.push(leftNode);
            }

            // Right child
            string rightVal = "";

            while (i < n && data[i] != ',') {
                rightVal += data[i];
                i++;
            }
            i++;

            if (rightVal != "#") {
                TreeNode* rightNode = new TreeNode(stoi(rightVal));
                currNode->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));