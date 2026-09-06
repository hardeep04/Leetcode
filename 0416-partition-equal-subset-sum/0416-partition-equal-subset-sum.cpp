class Solution {
public:
    bool fun(vector<int>& nums, int i, int s1, int sum,vector<vector<int>>& dp){
        int n=nums.size();
        if(s1 > sum) return 0;
        if(s1==sum && i==n) return 1;
        if(i==n) return 0; 
        if(dp[i][s1]!=-1) return dp[i][s1];
        bool left = fun(nums,i+1, s1+nums[i],sum,dp);
        bool right = fun(nums,i+1, s1,sum,dp);
        return dp[i][s1] = left | right;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int sum = accumulate(nums.begin(), nums.end(),0);
        if((sum&1)) return 0;
        vector<vector<int>> dp(n, vector<int>((sum>>1)+1,-1));
        return fun(nums, 0, 0, (sum>>1), dp);
    }
};