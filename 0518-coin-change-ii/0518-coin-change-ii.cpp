class Solution {
public:
    int fun(vector<int>&v, int target, int i,vector<vector<int>>& dp){
        if(target==0) return 1;
        if(i==v.size()){
            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int left=0;
        if(target>=v[i]) left = fun(v, target-v[i], i, dp);
        int right=fun(v, target, i+1, dp); 
        return dp[i][target] = left+right;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return fun(coins, amount, 0, dp);
    }
};