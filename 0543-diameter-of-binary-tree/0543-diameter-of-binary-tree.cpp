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
    int res = 0;
    int height(TreeNode* root){
        if(root==nullptr) return 0;
        int lh = height(root->left);
        int rt = height(root->right);
        res = max(res,lh + rt);
        return 1 + max(lh,rt);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return res;
    }
};