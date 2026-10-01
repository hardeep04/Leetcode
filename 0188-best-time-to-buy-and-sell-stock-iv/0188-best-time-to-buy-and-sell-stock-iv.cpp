class Solution {
public:
    int fun(vector<int>& prices, int limit, bool buy, int i, int dp[prices.size()][2][101]){
        if(limit==0) return 0;
        if(i==prices.size()-1){
            if(buy) return 0;
            return prices[i];
        }
        if(dp[i][buy][limit] != -1) return dp[i][buy][limit];
        if(buy){
            int left = -prices[i] + fun(prices, limit, 0, i+1, dp);
            int right = fun(prices, limit, 1, i+1, dp);
            return dp[i][buy][limit] = max(left, right);
        }
        else{
            int left = prices[i] + fun(prices, limit-1, 1, i, dp);
            int right = fun(prices, limit, 0, i+1, dp);
            return dp[i][buy][limit] = max(left, right);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int dp[prices.size()][2][101];
        memset(dp, -1, sizeof(dp));
        return fun(prices, k, 1, 0, dp);
    }
};