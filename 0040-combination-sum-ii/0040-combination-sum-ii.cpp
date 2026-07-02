class Solution {
public:
    void fun(vector<int>& v, int target, vector<vector<int>> &ans, vector<int> &temp, int i){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int in = i; in < v.size(); in++){
            if(in>i && v[in-1] == v[in]) continue;
            if(v[in]>target) break;
            temp.push_back(v[in]);
            fun(v,target-v[in], ans, temp, in+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        fun(candidates, target, ans, temp, 0);
        return ans;
    }
};