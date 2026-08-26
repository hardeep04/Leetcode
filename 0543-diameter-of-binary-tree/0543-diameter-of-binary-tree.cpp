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
    int depth(TreeNode* root){
        if(!root) return 0;
        int lh = depth(root->left);
        int rh = depth(root->right);
        return 1 + max(lh,rh);
    }
    int ans=0;
    void dfs(TreeNode* root){
        if(!root) return;
        ans = max(ans, depth(root->left) + depth(root->right));
        dfs(root->left);
        dfs(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;         
    }
};