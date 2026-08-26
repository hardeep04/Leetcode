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
            // q.pop();
            vector<int> v;
            for(int i=0; i<x; i++){
                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                q.pop();
                temp=q.front();
            }
            if((b&1)==0) reverse(v.begin(), v.end());
            ans.push_back(v);
        }
        return ans;
    }
};