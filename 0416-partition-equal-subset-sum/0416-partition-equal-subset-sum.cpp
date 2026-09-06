class Solution {
public:
    // bool fun(vector<int>& nums, int i, int s1, int sum,vector<vector<int>>& dp){
    //     int n=nums.size();
    //     if(s1 > sum) return 0;
    //     if(s1==sum && i==n) return 1;
    //     if(i==n) return 0; 
    //     if(dp[i][s1]!=-1) return dp[i][s1];
    //     bool left = fun(nums,i+1, s1+nums[i],sum,dp);
    //     bool right = fun(nums,i+1, s1,sum,dp);
    //     return dp[i][s1] = left | right;
    // }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int sum = accumulate(nums.begin(), nums.end(),0);
        int target = (sum>>1);
        if((sum&1)) return 0;
        vector<vector<int>> dp(n+1, vector<int>(target+1,0));
        // return fun(nums, 0, 0, (sum>>1), dp);

        for(int i=0; i<=n; i++) dp[i][0]=1;

        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=target; j++){
                bool left=0;
                if(j>=nums[i]) left=dp[i+1][j-nums[i]];
                bool right = dp[i+1][j];
                dp[i][j] = left | right;
            }
        }
        return dp[0][target];
    }
};