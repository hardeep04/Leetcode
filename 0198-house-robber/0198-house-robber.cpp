class Solution {
public:
    // int fun(int i, vector<int>& nums,vector<int>& dp){
    //     if(i>=nums.size()){
    //         return 0;
    //     }
    //     if(dp[i]!=-1) return dp[i];
    //     int left = nums[i] + fun(i+2, nums,dp);
    //     int right = fun(i+1, nums,dp);
    //     return dp[i] = max(left, right);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        // fun(0, nums, dp);
        // return dp[0];
        dp[0]=nums[0];
        for(int i=1; i<n; i++){
            int take = nums[i];
            if(i>1) take+=dp[i-2];
            int nottake = dp[i-1];
            dp[i] = max(take,nottake);
        }
        return dp[n-1];
    }
};