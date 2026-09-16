class Solution {
public:
    // int fun(vector<int>&v, int target, int i,vector<vector<int>>& dp){
    //     if(i==v.size()-1){
    //         if(target % v[i] ==0){
    //             return target / v[i];
    //         }
    //         return 1e9;
    //     }
    //     if(dp[i][target]!=-1) return dp[i][target];
    //     int left=1e9;
    //     if(target>=v[i]) left = 1 + fun(v, target-v[i], i, dp);
    //     int right=fun(v, target, i+1, dp); 
    //     return dp[i][target] = min(left, right);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        // int ans = fun(coins, amount, 0, dp);
        // if(ans == 1e9) return -1; 
        // return ans;
        for(int j=1; j<=amount; j++){
            if(j % coins[n-1] == 0) dp[n-1][j] = j/coins[n-1];
            else dp[n-1][j] = 1e9;
        }
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<=amount; j++){
                int left=1e9;
                if(j>=coins[i]) left = 1 + dp[i][j-coins[i]];
                int right=dp[i+1][j]; 
                dp[i][j] = min(left, right);
            }
        }
        return dp[0][amount] == 1e9 ? -1 : dp[0][amount];
    }
};