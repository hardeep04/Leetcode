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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int b = 0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            int x = q.size();
            b++;
            vector<int> v(x);
            for(int i=0; i<x; i++){
                if(b&1) v[i] = temp->val;
                else v[x-i-1] = temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                q.pop();
                temp=q.front();
            }
            ans.push_back(v);
        }
        return ans;
    }
};