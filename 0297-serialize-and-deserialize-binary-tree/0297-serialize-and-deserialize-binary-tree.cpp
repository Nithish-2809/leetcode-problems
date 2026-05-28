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

    // SERIALIZE
    void preorder(TreeNode* root, string &s) {

        if(root == NULL) {
            s += "N ";
            return;
        }

        s += to_string(root->val) + " ";

        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {

        string s = "";

        preorder(root, s);

        return s;
    }

    
    // DESERIALIZE
    TreeNode* buildTree(vector<string> &nodes, int &i) {

        if(nodes[i] == "N") {
            i++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++;

        root->left = buildTree(nodes, i);
        root->right = buildTree(nodes, i);

        return root;
    }

    TreeNode* deserialize(string data) {

        vector<string> nodes;
        string temp = "";

        // split string by spaces
        for(char ch : data) {

            if(ch == ' ') {
                nodes.push_back(temp);
                temp = "";
            }
            else {
                temp += ch;
            }
        }

        int i = 0;

        return buildTree(nodes, i);
    }
};