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
    int ans=0;
    void fun(TreeNode* root, int temp){
        if(!root){
            ans = max(ans, temp-1);
            return;
        } 
        fun(root->left, temp+1);
        fun(root->right, temp+1);
    }
    int maxDepth(TreeNode* root) {
        fun(root, 1);
        return ans;
    }
};