class Solution {
public:
    int fun(int i, vector<int>& nums,vector<int>& dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int left = nums[i] + fun(i+2, nums,dp);
        int right = fun(i+1, nums,dp);
        return dp[i] = max(left, right);
    }
    int rob(vector<int>& nums) {
        int maxi=0, n=nums.size();
        vector<int> dp(n,-1);
        fun(0, nums, dp);
        return dp[0];
    }
};