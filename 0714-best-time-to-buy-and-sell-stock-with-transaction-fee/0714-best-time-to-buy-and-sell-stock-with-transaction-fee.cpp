class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int dp[n+1][2];
        memset(dp, 0, sizeof(dp));
        for (int i = n - 1; i >= 0; i--) {
            int left = -prices[i] + dp[i + 1][0];
            int right = dp[i + 1][1];
            dp[i][1] = max(left, right);
                
            int l = prices[i] - fee + dp[i+1][1];
            int r = dp[i + 1][0];
            dp[i][0] = max(l, r);
        }
        return dp[0][1];
    }
};