class Solution {
public:
    void fun(vector<int>& v, int target, vector<vector<int>> &ans, vector<int> &temp, int i){
        if(target<0) return;
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i==v.size()){
            return;
        } 
        temp.push_back(v[i]);
        fun(v,target-v[i], ans, temp, i);
        temp.pop_back();
        fun(v,target, ans, temp, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(candidates, target, ans, temp, 0);
        return ans;
    }
};