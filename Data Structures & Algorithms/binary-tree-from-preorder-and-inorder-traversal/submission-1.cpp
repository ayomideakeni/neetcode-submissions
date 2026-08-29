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
public:
    unordered_map<int, int> inorderMap;
    int preIdx = 0;
    TreeNode* build(vector<int>& preorder, int start, int end){
       if(start > end){
        return nullptr;
       }

       int rootVal = preorder[preIdx++];
       int rootIdx = inorderMap[rootVal];

       TreeNode* node = new TreeNode(rootVal);
       node->left = build(preorder, start, rootIdx - 1);
       node->right = build(preorder, rootIdx + 1, end);
       

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i){
            inorderMap[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1);
    }
};