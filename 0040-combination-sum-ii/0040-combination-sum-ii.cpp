class Solution {
public:
    void fun(vector<int>& v, int target, vector<vector<int>> &ans, vector<int> &temp, int i){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i==v.size() || target<0){
            return;
        }
        if(v[i]<=target){
            temp.push_back(v[i]);
            fun(v,target-v[i], ans, temp, i+1);
            temp.pop_back();
        }
        while (i + 1 < v.size() && v[i] == v[i + 1]) {
            i++;
        }
        fun(v, target, ans, temp, i + 1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        fun(candidates, target, ans, temp, 0);
        return ans;
    }
};