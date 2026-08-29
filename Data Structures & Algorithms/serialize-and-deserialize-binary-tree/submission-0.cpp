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

    // Encodes a tree to a single string.

    void res(TreeNode* root, string& s){
        if(!root){
            s += "N,";
            return;
        }
        s += to_string(root->val) + ",";
        res(root->left, s);
        res(root->right, s);
    }
    string serialize(TreeNode* root) {
       string result = "";
       res(root, result);
       return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* build(stringstream& ss){
        string item;
        if(!getline(ss, item, ',')) return nullptr;
        if(item == "N") return nullptr;

        TreeNode* root = new TreeNode(stoi(item));
        root->left = build(ss);
        root->right = build(ss);
        return root;

    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));