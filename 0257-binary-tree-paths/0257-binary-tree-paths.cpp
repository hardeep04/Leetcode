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
    vector<string> ans;
    void fun(TreeNode* root, string s){
       if(root->left){
            string t="->";
            t+=to_string(root->left->val);
            fun(root->left, s+t);
       }
       if(root->right){
            string t="->";
            t+=to_string(root->right->val);
            fun(root->right, s+t);
       }
       if(!root->left && !root->right){
            ans.push_back(s);
            return;
       } 

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        fun(root, to_string(root->val));
        return ans;
    }
};