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
    int maxSum = INT_MIN;

    int sumPaths(TreeNode* root){
        if(!root) return 0;
        int nodeVal = root->val;

        int left = max(sumPaths(root->left), 0);
        int right = max(sumPaths(root->right), 0);
        

        maxSum = max(maxSum, nodeVal +(right + left));

        return nodeVal + max(left, right);

    }

    int maxPathSum(TreeNode* root) {
        sumPaths(root);
        return maxSum;

    }
};