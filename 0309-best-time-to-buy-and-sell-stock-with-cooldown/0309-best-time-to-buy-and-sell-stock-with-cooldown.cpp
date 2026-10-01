class Solution {
public:
    int fun(vector<int> &prices, bool buy, int i, vector<vector<int>>& dp){
        int n = prices.size();
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            int left = -prices[i] + fun(prices, 0, i+1, dp);
            int right = fun(prices, 1, i+1, dp);
            return dp[i][1] = max(left, right);
        }
        else{
            int left = prices[i] + fun(prices, 1, i+2, dp);
            int right = fun(prices, 0, i+1, dp);
            return dp[i][0] = max(left, right);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); 
        return fun(prices, 1, 0, dp);
    }
};