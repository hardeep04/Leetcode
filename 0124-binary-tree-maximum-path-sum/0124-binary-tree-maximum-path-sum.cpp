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
    int maxi=INT_MIN;
    int depth(TreeNode* root){
        if(!root) return 0;
        int lh = depth(root->left);
        int rh = depth(root->right);
        if(lh < 0) lh = 0;
        if(rh < 0) rh = 0;
        maxi = max(maxi, root->val + lh + rh);
        return root->val + max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        depth(root);
        return maxi;
    }
};