class Solution {
public:
    // int fun(int i, int j, vector<int>& nums, vector<int> &dp){
    //     if(i>j) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int take = nums[i] + fun(i+2,j,nums,dp);
    //     int nottake = fun(i+1,j,nums,dp);
    //     return dp[i] = max(take,nottake);
    // }

    // tabulation --------------------------------
    // int fun(int s, int e, vector<int>& nums, vector<int> &dp){
    //     for(int i=s+1; i<=e; i++){
    //         int take = nums[i];
    //         if(i>s+1) take += dp[i-2];
    //         int nottake = dp[i-1];
    //         dp[i] = max(take,nottake);
    //     }
    //     return dp[e];
    // }
    
    //after space optimization--------------------
    int fun(int s, int e, vector<int>& nums, vector<int> &dp){
        int prev2=0, prev=nums[s];
        for(int i=s+1; i<=e; i++){
            int take = nums[i] + prev2;
            int nottake = prev;
            int curr = max(take,nottake);

            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1), dp2(n,-1);
        dp[0] = nums[0], dp2[1] = nums[1];
        return max(fun(0,n-2, nums, dp), fun(1,n-1, nums, dp2));
    }
};