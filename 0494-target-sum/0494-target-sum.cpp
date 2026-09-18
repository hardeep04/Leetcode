class Solution {
public:
    // int fun(vector<int>& arr, int t, int i, int x, vector<vector<int>>& dp){
    //     if(i==arr.size()){
    //         if(x==t) return 1;
    //         return 0;
    //     }
    //     if(dp[i][x+20000] != -1) return dp[i][x+20000];
    //     int left = fun(arr, t, i+1, x+arr[i], dp);
    //     int right = fun(arr, t, i+1, x-arr[i], dp);
    //     return dp[i][x+20000] = left+right;
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        // vector<vector<int>> dp(n, vector<int>(40001, -1));
        // return fun(nums, target, 0, 0, dp);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target)>sum) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));

        dp[n][sum] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = -sum; j <= sum; j++) {
                if (dp[i + 1][j + sum] > 0) {
                    if (j + nums[i] <= sum) {
                        dp[i][j + nums[i] + sum] += dp[i + 1][j + sum];
                    }
                    if (j - nums[i] >= -sum) {
                        dp[i][j - nums[i] + sum] += dp[i + 1][j + sum];
                    }
                }
            }
        }
        return dp[0][target + sum];
    }
};