class Solution {
public:
    // int fun(vector<int>& prices, int limit, bool buy, int i, int
    // dp[prices.size()][2][101]){
    //     if(limit==0) return 0;
    //     if(i==prices.size()-1){
    //         if(buy) return 0;
    //         return prices[i];
    //     }
    //     if(dp[i][buy][limit] != -1) return dp[i][buy][limit];
    //     if(buy){
    //         int left = -prices[i] + fun(prices, limit, 0, i+1, dp);
    //         int right = fun(prices, limit, 1, i+1, dp);
    //         return dp[i][buy][limit] = max(left, right);
    //     }
    //     else{
    //         int left = prices[i] + fun(prices, limit-1, 1, i, dp);
    //         int right = fun(prices, limit, 0, i+1, dp);
    //         return dp[i][buy][limit] = max(left, right);
    //     }
    // }
    int maxProfit(int k, vector<int>& prices) {
        // int dp[prices.size()][2][101];
        // memset(dp, -1, sizeof(dp));
        // return fun(prices, k, 1, 0, dp);
        int n = prices.size();
        int dp[n+1][2][k + 1];
        memset(dp, 0, sizeof(dp));
        for (int limit = 1; limit <= k; limit++) {
            dp[n - 1][0][limit] = prices[n - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int limit = k; limit >= 0; limit--) {
                int left = -prices[i] + dp[i + 1][0][limit];
                int right = dp[i + 1][1][limit];
                dp[i][1][limit] = max(left, right);

                int l = 0;
                if(limit>=1) l = prices[i] + dp[i+1][1][limit - 1];
                int r = dp[i + 1][0][limit];
                dp[i][0][limit] = max(l, r);
            }
        }
        return dp[0][1][k];
    }
};