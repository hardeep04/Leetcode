class Solution {
public:
    // int fun(vector<int>&v, int target, int i,vector<vector<int>>& dp){
    //     if(target==0) return 1;
    //     if(i==v.size()){
    //         return 0;
    //     }
    //     if(dp[i][target]!=-1) return dp[i][target];
    //     int left=0;
    //     if(target>=v[i]) left = fun(v, target-v[i], i, dp);
    //     int right=fun(v, target, i+1, dp); 
    //     return dp[i][target] = left+right;
    // }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // return fun(coins, amount, 0, dp);
        // vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        vector<unsigned int> prev(amount + 1, 0);
        prev[0]=1;
        // for(int i=0; i<=n; i++) dp[i][0] = 1;
        for(int i=n-1; i>=0; i--){
            vector<unsigned int> curr(amount+1, 0);
            curr[0]=1;
            for(int j=1; j<=amount; j++){
                unsigned int left=0;
                if(j>=coins[i]) left = curr[j-coins[i]];
                unsigned int right=prev[j]; 
                curr[j] = left+right;
            }
            prev=curr;
        }
        return static_cast<int> (prev[amount]);
    }
};