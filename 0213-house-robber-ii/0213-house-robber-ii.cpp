class Solution {
public:
    int fun(int i, int j, vector<int>& nums, vector<int> &dp){
        if(i>j) return 0;
        if(dp[i]!=-1) return dp[i];
        int take = nums[i] + fun(i+2,j,nums,dp);
        int nottake = fun(i+1,j,nums,dp);
        return dp[i] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1), dp2(n,-1);
        return max(fun(0,n-2, nums, dp), fun(1,n-1, nums, dp2));
    }
};