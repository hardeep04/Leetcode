class Solution {
public:
    void fun(vector<int>& nums, int maxDiff, vector<vector<int>>& q, vector<bool>& ans){
        int n = nums.size(); 
        vector<int> component(n,0);
        int b=0;
        for(int i=1; i<n; i++){
            if(nums[i] - nums[i-1] > maxDiff) b++;
            component[i] = b;
        }
        for(auto& v : q){
            if(component[v[0]] == component[v[1]]) ans.push_back(1);
            else ans.push_back(0);
        }
        return;
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        fun(nums, maxDiff,queries, ans);
        return ans;
    }
};