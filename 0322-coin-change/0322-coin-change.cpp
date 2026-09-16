class Solution {
public:
    int fun(vector<int>&v, int target, int i,vector<vector<int>>& dp){
        if(i==v.size()-1){
            if(target % v[i] ==0){
                return target / v[i];
            }
            return 1e9;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int left=1e9;
        if(target>=v[i]) left = 1 + fun(v, target-v[i], i, dp);
        int right=fun(v, target, i+1, dp); 
        return dp[i][target] = min(left, right);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = fun(coins, amount, 0, dp);
        if(ans == 1e9) return -1; 
        return ans;
    }
};